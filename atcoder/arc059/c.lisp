#!/usr/bin/sbcl --script
;; https://arc059.contest.atcoder.jp/tasks/arc059_a
(let* ((n (read))
			 (a (make-array n :initial-contents (loop :repeat n :collect (read))))
			 (avg (round (reduce #'+ a) (length a))))
	(loop
		 :for x :across a
		 :summing (expt (- x avg) 2) :into s
		 :finally (format t "~a~%" s)))
