#!/usr/bin/sbcl --script
;; https://code.google.com/codejam/contest/2974486/dashboard#s=p0
(defun read-cards ()
	(loop repeat 4
		 collect (list (read) (read) (read) (read))))

(defun read-problem ()
	(values (read) (read-cards) (read) (read-cards)))

(defun problem ()
	(multiple-value-bind (a1 c1 a2 c2) (read-problem)
		(let ((intersection (intersection (nth (1- a1) c1) (nth (1- a2) c2))))
			(case (length intersection)
				(0 "Volunteer cheated!")
				(1 (car intersection))
				(otherwise "Bad magician!")))))

(loop for i from 1 to (read)
	 do (format t "Case #~a: ~a~%" i (problem)))
		 
