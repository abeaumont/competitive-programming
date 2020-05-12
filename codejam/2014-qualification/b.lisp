#!/usr/bin/sbcl --script
;; https://code.google.com/codejam/contest/2974486/dashboard#s=p1
(defun best-time (c f x)
	(labels ((iter (farms target acc)
						 (let ((buy (+ (/ c farms) (/ target (+ farms f))))
									 (no-buy (/ target farms)))
							 (if (< no-buy buy)
									 (+ acc no-buy)
									 (iter (+ farms f) target (+ acc (/ c farms)))))))
		(iter 2 x 0)))

(let ((*read-default-float-format* 'double-float))
	(loop for i from 1 to (read)
		 do (format t "Case #~a: ~7$~%" i (best-time (read) (read) (read)))))
