#!/usr/bin/sbcl --script
;; https://www.hackerrank.com/challenges/hackerland-radio-transmitters
(loop
   :with n = (read)
   :with k = (read)
   :with a = (sort (make-array n :initial-contents (loop :repeat n :collect (read))) #'<)
   :with j = (aref a 0)
   :and c = 1
   :and i = 0
   :while (< i n)
   :do
     (if (> (aref a i) (+ k j))
         (progn
           (setf j (+ 1 k (aref a (1- i))))
           (loop
              :while (and (< i n) (< (aref a i) j))
              :do (incf i))
           (when (< i n)
             (incf c)
             (setf j (aref a i))))
         (incf i))
   :finally (format t "~a~%" c))
