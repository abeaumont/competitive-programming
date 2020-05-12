#!/usr/bin/env racket
;; https://codingcompetitions.withgoogle.com/codejam/round/0000000000201bee/0000000000201b6d
#lang racket
(require math/number-theory)

(define (process n j)
  (define (collect i s)
    (cons (format "~b" i)
          (map (lambda (x)
                 (number->string (second (divisors (string->number s x)))))
               (range 2 11))))
  (define (no-primes? s)
    (define (iter i)
      (cond ([> i 10] #t)
            ([prime? (string->number s i)] #f)
            (else (iter (+ i 1)))))
    (iter 2))
  (define (iter i k xs)
    (if (= k j)
        xs
        (let ([s (format "~b" i)])
          (if (no-primes? s)
              (iter (+ i 2) (+ k 1) (cons (collect i s) xs))
              (iter (+ i 2) k xs)))))
  (iter (+ (expt 2 (- n 1)) 1) 0 '()))

(define (main n)
  (define (iter i)
    (when (<= i n)
      (printf "Case #~a:\n" i)
      (for-each (lambda (x) (printf "~a\n" (string-join x)))
                (apply process (map string->number (string-split (read-line)))))))
  (iter 1))
(main (string->number (read-line)))
