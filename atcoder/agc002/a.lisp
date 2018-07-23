#!/usr/bin/sbcl --script
(let ((a (read))
      (b (read)))
  (format t "~a~%"
          (cond ((> a 0) "Positive")
                ((>= b 0) "Zero")
                ((zerop (mod (- a b) 2)) "Negative")
                (t "Positive"))))
