#!/usr/bin/env newlisp
(define (input)
  (if (read-line)
    (let ((xs (map int (explode (current-line)))))
      (cons (array (length xs) xs) (input)))
    '()))

(define (coords i j)
  (let ((xs (map (fn (p) (cons (+ i (first p)) (+ j (last p))))
                 '((-1 -1) (-1 0) (-1 1) (0 -1) (0 1) (1 -1) (1 0) (1 1)))))
    (filter (fn (p)
              (let ((i (first p))
                    (j (last p)))
                (and (>= i 0) (< i m)
                     (>= j 0) (< j n)
                     (< (a i j) 10))))
            xs)))

(define (init i j)
  (cond
   ((= i m) '())
   ((= j n) (init (+ i 1) 0))
   (true (cons (cons i j) (init i (+ j 1))))))

(define (update-point p xs)
  (let ((i (first p))
        (j (last p)))
    (cond
     ((>= (a i j) 10) xs)
     ((< (a i j) 9) (++ (a i j)) xs)
     (true (++ (a i j)) (append (coords i j) xs)))))

(define (update xs)
  (unless (empty? xs)
    (update (update-point (first xs) (rest xs)))))

(define (flash i j)
  (cond
   ((= i m) 0)
   ((= j n) (flash (+ i 1) 0))
   ((< (a i j) 10) (flash i (+ j 1)))
   (true (setf (a i j) 0) (+ 1 (flash i (+ j 1))))))

(define (step)
  (update (init 0 0))
  (flash 0 0))

(define (steps i)
  (if (= (step) (* m n))
      i
      (steps (+ i 1))))

(define (main input)
  (let (m (length input))
    (if (zero? m)
        0
        (letn ((a (array m input))
               (n (length (a 0))))
          (steps 1)))))

(println (main (input)))
