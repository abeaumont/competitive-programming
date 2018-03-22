;; https://www.hackerrank.com/challenges/sherlock-and-the-beast
(dotimes (_ (read))
  (format t "~a~%"
          (loop with n = (read)
                for k = (* (floor n 3) 3) then (- k 3)
                while (> k 0)
                when (zerop (mod (- n k) 5))
                  do (return (concatenate 'string
                                          (make-string k :initial-element #\5)
                                          (make-string (- n k) :initial-element #\3)))
                finally (return (if (zerop (mod n 5)) (make-string n :initial-element #\3) -1)))))
