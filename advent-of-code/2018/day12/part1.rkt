#!/usr/bin/env racket
#lang racket

(define (string->pair s)
  (let ([xs (string-split s " => ")])
    (cons (first xs) (string-ref (second xs) 0))))

(let* ([ls (sequence->list (in-lines))]
       [l (second (string-split (first ls) ": "))]
       [ll (string-length l)]
       [x (make-vector (+ 60 ll) #\.)]
       [xl (vector-length x)]
       [h (make-hash (map string->pair (cddr ls)))])
  (for ([i ll]
        [v l])
    (vector-set! x (+ i 30) v))
  (for ([_ 20])
    (let ((y (vector-copy x)))
      (for ([i (in-range 2 (- xl 2))])
        (let ([k (apply string (vector->list (vector-copy x (- i 2) (+ i 3))))])
          (vector-set! y i (hash-ref h k)) (vector-ref x i)))
      (vector-copy! x 0 y)))
  (displayln
   (for/fold ([sum 0])
             ([i xl]
              [v x])
     (+ sum (if (char=? #\# v) (- i 30) 0)))))
