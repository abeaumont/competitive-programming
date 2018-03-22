;; https://www.hackerrank.com/challenges/angry-professor
(dotimes (_ (read))
  (let ((n (read))
        (k (read)))
    (format t "~a~%" (loop repeat n
                           counting (<= (read) 0) into counter
                           finally (return (if (< counter k) "YES" "NO"))))))
