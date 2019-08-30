;; https://cses.fi/problemset/task/1072/
(defun all (n)
  (/ (* n (1- n)) 2))

(defun attacks (n)
  (* 2 (- n 2) (+ (* 2 (- n 4)) 6)))

(defun valid (n)
  (- (all (* n n)) (attacks n)))

(loop :for i :from 1 :to (read) :do (format t "~a~%" (valid i)))
