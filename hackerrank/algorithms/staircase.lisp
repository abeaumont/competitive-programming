;; https://www.hackerrank.com/challenges/staircase
(let ((n (read)))
  (dotimes (i n)
    (dotimes (_ (- n (1+ i)))
      (format t "~a" #\Space))
    (dotimes (_ (1+ i))
      (format t "~a" #\#))
    (terpri)))
