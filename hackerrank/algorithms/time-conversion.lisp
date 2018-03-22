;; https://www.hackerrank.com/challenges/time-conversion
(let ((s (read-line)))
  (format t "~a~%" (if (char= (char s 8) #\A)
                       (if (string= (subseq s 0 2) "12")
                           (concatenate 'string "00" (subseq s 2 8))
                           (subseq s 0 8))
                       (if (string= (subseq s 0 2) "12")
                           (subseq s 0 8)
                           (concatenate 'string (format nil "~a" (+ 12 (parse-integer (subseq s 0 2)))) (subseq s 2 8))))))
