#lang racket
(require parser-tools/lex
         (prefix-in re- parser-tools/lex-sre)
         parser-tools/yacc)

(define-tokens a (NUM))
(define-empty-tokens b (LPAR RPAR x + - * / NEG NONE ^ EOF))

(define-lex-trans number
  (syntax-rules ()
    ((_ digit) (re-+ digit))))

(define-lex-abbrevs
  (digit10 (char-range "0" "9"))
  (number10 (number digit10)))

(define alg-lexer
  (lexer
   ("(" (token-LPAR))
   (")" (token-RPAR))
   ("^" (token-^))
   ("*" (token-*))
   ("/" (token-/))
   ("-" (token--))
   ("+" (token-+))
   ("x" (token-x))
   ((re-+ number10) (token-NUM (string->number lexeme)))
   (whitespace (alg-lexer input-port))
   ((eof) (token-EOF))))

(define-struct paren-exp (e))
(define-struct arith-exp (op e1 e2))
(define-struct neg-exp (e))
(define-struct x-exp (rank value))

(define alg-parser
  (parser
   (start exp)
   (end EOF)
   (error void)
   (tokens a b)
   (precs
    (left NONE)
    (left x NUM LPAR RPAR)
    (left + -)
    (left * /)
    (left NEG)
    (right ^)
    )
   (grammar
    (exp
     ((NUM) (make-x-exp 0 $1))
     ((x) (make-x-exp 1 1))
     ((exp + exp) (make-arith-exp 'ADD $1 $3))
     ((exp - exp) (make-arith-exp 'SUB $1 $3))
     ((exp * exp) (make-arith-exp 'MUL $1 $3))
     ((exp / exp) (make-arith-exp 'DIV $1 $3))
     ((+ exp) $2)
     ((- exp) (prec NEG) (make-neg-exp $2))
     ((exp ^ exp) (make-arith-exp 'EXP $1 $3))
     ((LPAR exp RPAR) (prec LPAR) $2)))))

(define (neg xs)
  (map (lambda (x)
         (make-x-exp (x-exp-rank x)
                     (- (x-exp-value x))))
       xs))

(define (add xs ys)
  (match (cons xs ys)
    ((cons (list) (list)) (list))
    ((cons (list) _) ys)
    ((cons _ (list)) xs)
    ((cons (cons x xs2) (cons y ys2))
     (cond ((> (x-exp-rank x) (x-exp-rank y))
            (cons x (add xs2 ys)))
           ((< (x-exp-rank x) (x-exp-rank y))
            (cons y (add xs ys2)))
           (else
            (cons (make-x-exp (x-exp-rank x)
                              (+ (x-exp-value x)
                                 (x-exp-value y)))
                  (add xs2 ys2)))))))

(define (sub xs ys)
  (match (cons xs ys)
    ((cons (list) (list)) (list))
    ((cons (list) ys) (map (lambda (y) (make-x-exp (x-exp-rank y)
                                              (- (x-exp-value y))))
                           ys))
    ((cons xs (list)) xs)
    ((cons (cons x xs2) (cons y ys2))
     (cond ((> (x-exp-rank x) (x-exp-rank y))
            (cons x (sub xs2 ys)))
           ((< (x-exp-rank x) (x-exp-rank y))
            (cons (make-x-exp (x-exp-rank y)
                              (- (x-exp-value y)))
                  (sub xs ys2)))
           (else
            (cons (make-x-exp (x-exp-rank x)
                              (- (x-exp-value x)
                                 (x-exp-value y)))
                  (sub xs2 ys2)))))))

(define (merge xs)
  (match xs
    ((list) (list))
    ((list a) xs)
    ((list a b)
     (if (= (x-exp-rank a)
            (x-exp-rank b))
         (list (make-x-exp (x-exp-rank a)
                           (+ (x-exp-value a)
                              (x-exp-value b))))
         xs))
    ((list-rest a b c)
     (if (= (x-exp-rank a)
            (x-exp-rank b))
         (merge (cons (make-x-exp (x-exp-rank a)
                                  (+ (x-exp-value a)
                                     (x-exp-value b)))
                      c))
         (cons a (merge (cons b c)))))))

(define (simplify xs)
  (let ((sorted (sort xs #:key x-exp-rank >)))
    (merge sorted)))
    

(define (mul xs ys)
  (simplify (apply append (map (lambda (x)
                                 (map (lambda (y)
                                        (make-x-exp (+ (x-exp-rank x)
                                                       (x-exp-rank y))
                                                    (* (x-exp-value x)
                                                       (x-exp-value y))))
                                      ys))
                               xs))))

(define (div xs ys)
  (map (lambda (x)
         (make-x-exp (x-exp-rank x)
                     (/ (x-exp-value x)
                        (x-exp-value (car ys)))))
       xs))

(define (pow-iter i x acc)
  (if (= i 0)
      acc
      (pow-iter (- i 1) x (mul x acc))))

(define (pow xs ys)
  (let ((k (x-exp-value (car ys))))
    (pow-iter (- k 1) xs xs)))
  
(define (eval parsed-exp)
  (match parsed-exp
    ((neg-exp e) (neg (eval e)))
    ((arith-exp op e1 e2)
     (case op
       ('ADD (add (eval e1) (eval e2)))
       ('SUB (sub (eval e1) (eval e2)))
       ('MUL (mul (eval e1) (eval e2)))
       ('DIV (div (eval e1) (eval e2)))
       ('EXP (pow (eval e1) (eval e2)))))
    ((paren-exp e) (eval e))
    ((x-exp rank value) (list (x-exp rank value)))))

(define (print-exp-inner es)
  (if (null? es)
      (list)
      (let* ((rank (x-exp-rank (car es)))
             (value (x-exp-value (car es)))
             (s (cond ((= value 0) "")
                      ((and (= rank 0) (< value 0)) (format " - ~a" (abs value)))
                      ((= rank 0) (format " + ~a" value))
                      ((and (= rank 1) (= value -1)) (format " - x"))
                      ((and (= rank 1) (= value 1)) (format " + x"))
                      ((and (= rank 1) (< value 0)) (format " - ~ax" (abs value)))
                      ((= rank 1) (format " + ~ax" value))
                      ((= value -1) (format " - x^~a" rank))
                      ((= value 1) (format " + x^~a" rank))
                      ((< value 0) (format " - ~ax^~a" (abs value) rank))
                      (else (format " + ~ax^~a" value rank)))))
        (cons s (print-exp-inner (cdr es))))))

(define (print-exp es)
  (if (null? es)
      (list "0")
      (let* ((rank (x-exp-rank (car es)))
             (value (x-exp-value (car es)))
             (s (cond ((= value 0) (if (null? (cdr es)) "0" ""))
                      ((and (= rank 0) (< value 0)) (format "-~a" (abs value)))
                      ((= rank 0) (format "~a" value))
                      ((and (= rank 1) (= value -1)) (format "-x"))
                      ((and (= rank 1) (= value 1)) (format "x"))
                      ((and (= rank 1) (< value 0)) (format "-~ax" (abs value)))
                      ((= rank 1) (format "~ax" value))
                      ((= value -1) (format "-x^~a" rank))
                      ((= value 1) (format "x^~a" rank))
                      ((< value 0) (format "-~ax^~a" (abs value) rank))
                      (else (format "~ax^~a" value rank)))))
        (cons s (print-exp-inner (cdr es))))))

(define (clean es)
  (filter (lambda (x) (not (zero? (x-exp-value x)))) es))
  
(define (pr es)
  (displayln (string-join (print-exp (clean es)) "")))

(define (lex-this lexer input) (lambda () (lexer input)))

(define (eval-string str)
  ;;(displayln str)
  (let ((input (open-input-string str)))
    (pr (eval (alg-parser (lex-this alg-lexer input))))))

(define (loop i)
  (when (> i 0)
    (eval-string
     ;; Ugly hack to avoid implicit multiplications which were
     ;; causing problems with operator precedence
     (regexp-replace*
      #px"[)]x"
      (regexp-replace*
       #px"[)]([\\d]+)"
       (regexp-replace*
        #px"[)][(]"
        (regexp-replace*
         #px"x[(]"
         (regexp-replace*
          #px"([\\d]+)[(]" 
          (regexp-replace* #px"([\\d]+)x" (read-line) "\\1*x")
          "\\1*(")
         "x*(")
        ")*(")
       ")*\\1")
      ")*x"))
    (loop (- i 1))))

(loop (string->number (read-line)))
