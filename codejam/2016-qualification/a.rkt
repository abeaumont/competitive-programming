#!/usr/bin/env racket
;; https://codingcompetitions.withgoogle.com/codejam/round/0000000000201bee/0000000000201c8a
#lang racket
(require srfi/25)

(define (number->digits n)
  (define (iter n acc)
    (match n
      [0 acc]
      [_ (iter (quotient n 10) (cons (modulo n 10) acc))]))
  (iter n '()))

(define (update-digits v digits)
  (for-each (lambda (d) (vector-set! v d #t)) digits))

(define (all-digits? v)
  (not (vector-memq #f v)))

(define (process n)
  (let ([v (make-vector 10 #f)])
    (define (iter n i)
      (update-digits v (number->digits (* n i)))
      (if (all-digits? v)
          (* n i)
          (iter n (+ i 1))))
    (iter n 1)))

(define (main)
  (let ([n (read)])
    (define (iter i)
      (when (<= i n)
        (let ([k (read)])
          (printf "Case #~a: ~a\n" i (if (zero? k) "INSOMNIA" (process k)))
          (iter (+ i 1)))))
    (iter 1)))

(main)
