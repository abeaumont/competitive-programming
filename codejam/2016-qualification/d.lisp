#!/usr/bin/sbcl --script
;; https://codingcompetitions.withgoogle.com/codejam/round/0000000000201bee/0000000000201bf1
(defun process (k c s) (loop for i from 1 to k collect i))

(loop for i from 1 to (read)
      do (format t "Case #~a: ~{~a~^ ~}~%" i (process (read) (read) (read))))
