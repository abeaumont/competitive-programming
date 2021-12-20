(import (rnrs))

(define (char->bit char)
  (if (char=? char #\x23) 1 0))

(define (parse-lines xs line lines)
  (cond
   [(null? xs) (reverse lines)]
   [(char=? (car xs) #\newline)
    (parse-lines (cdr xs) '()
                 (cons (reverse (map char->bit line)) lines))]
   [else (parse-lines (cdr xs) (cons (car xs) line) lines)]))

(define (parse-input s)
  (list->vector
   (map list->vector
        (parse-lines (string->list s) '() '()))))

(define (index xs fill m n i j)
  (let ([cs (vector (cons (+ i 1) (+ j 1))
                    (cons (+ i 1) j)
                    (cons (+ i 1) (- j 1))
                    (cons i (+ j 1))
                    (cons i j)
                    (cons i (- j 1))
                    (cons (- i 1) (+ j 1))
                    (cons (- i 1) j)
                    (cons (- i 1) (- j 1)))]
        [sum 0])
    (do ([i 0 (+ i 1)])
        ((= i 9))
      (let* ([y (car (vector-ref cs i))]
             [x (cdr (vector-ref cs i))]
             [bit (if (or (< y 0) (>= y m) (< x 0) (>= x n))
                      fill
                      (vector-ref (vector-ref xs y) x))])
        (set! sum (+ sum (bitwise-arithmetic-shift-left bit i)))))
    sum))

(define (enhance-one xs a i)
  (let* ([m (vector-length xs)]
         [n (vector-length (vector-ref xs 0))]
         [fill (if (odd? i) (vector-ref a 0) 0)]
         [ys (make-vector (+ m 2))])
    (do ([i 0 (+ i 1)])
        ((= i (vector-length ys)))
      (vector-set! ys i (make-vector (+ n 2)))
      (do ([j 0 (+ j 1)])
          ((= j (vector-length (vector-ref ys i))))
        (vector-set! (vector-ref ys i) j
                     (vector-ref a (index xs fill m n (- i 1) (- j 1))))))
    ys))

(define (count xs)
  (let ([count 0])
    (do ([i 0 (+ i 1)])
        ((= i (vector-length xs)))
      (do ([j 0 (+ j 1)])
          ((= j (vector-length (vector-ref xs i))))
        (set! count (+ count (vector-ref (vector-ref xs i) j)))))
    count))

(define (enhance xs a n i)
  (if (= n 0)
      xs
      (enhance (enhance-one xs a i) a (- n 1) (+ i 1))))

(let* ([input (open-string-input-port
         (apply string (map integer->char
                            (bytevector->u8-list
                             (get-bytevector-all (standard-input-port))))))]
       [enhancement (list->vector (map char->bit (string->list (get-line input))))])
  (get-line input)
  (display (count (enhance (parse-input (get-string-all input)) enhancement 2 0)))
  (newline))
