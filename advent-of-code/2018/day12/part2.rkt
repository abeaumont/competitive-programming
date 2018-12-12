#!/usr/bin/env racket
#lang racket

(define (string->pair s)
  (let ([xs (string-split s " => ")])
    (cons (first xs) (string-ref (second xs) 0))))

(let* ([ls (sequence->list (in-lines))]
       [l (second (string-split (first ls) ": "))]
       [ll (string-length l)]
       [g 200]
       [x (make-vector (+ (* g 4) ll) #\.)]
       [xl (vector-length x)]
       [h (make-hash (map string->pair (cddr ls)))])
  (for ([i ll]
        [v l])
    (vector-set! x (+ i (* g 2)) v))
  (for ([r (in-range 1 g)])
    (let ((y (vector-copy x)))
      (for ([i (in-range 2 (- xl 2))])
        (let ([k (apply string (vector->list (vector-copy x (- i 2) (+ i 3))))])
          (vector-set! y i (hash-ref h k)) (vector-ref x i)))
      (let* ([s1 (vector-member #\# x)]
             [e1 (- xl (vector-member #\# (list->vector (reverse (vector->list x)))))]
             [xs (vector-copy x s1 (+ e1 1))]
             [s2 (vector-member #\# y)]
             [e2 (- xl (vector-member #\# (list->vector (reverse (vector->list y)))))]
             [ys (vector-copy y s2 (+ e2 1))])
        (when (equal? xs ys)
          (displayln
           (for/fold ([sum 0])
                     ([i (in-range s2 (+ e2 1))]
                      [v ys])
             (+ sum (if (char=? #\# v) (+ (- i (* g 2)) (* (- s2 s1) (- 50000000000 r))) 0))))
          (exit)))
      (vector-copy! x 0 y))))
