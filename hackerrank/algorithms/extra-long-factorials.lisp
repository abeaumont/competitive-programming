;; https://www.hackerrank.com/challenges/extra-long-factorials
(write (reduce #'* (loop for i from 1 to (read) collect i)))
