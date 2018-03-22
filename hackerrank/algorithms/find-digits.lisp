;; https://www.hackerrank.com/challenges/find-digits
(dotimes (_ (read))
  (let* ((s (read-line))
         (n (parse-integer s)))
    (format t "~a~%"
            (loop for i from 0 below (length s)
                  for k = (parse-integer s :start i :end (1+ i))
                  counting (and (not (zerop k)) (zerop (mod n k)))))))
