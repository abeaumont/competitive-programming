;; https://www.hackerrank.com/challenges/sherlock-and-squares
(dotimes (_ (read))
  (let ((a (ceiling (sqrt (read))))
        (b (floor (sqrt (read)))))
    (format t "~a~%" (1+ (- b a)))))
