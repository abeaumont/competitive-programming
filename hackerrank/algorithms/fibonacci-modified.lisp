;; https://www.hackerrank.com/challenges/fibonacci-modified
(let ((t1 (read))
			(t2 (read))
			(n (read)))
	(loop :for i :from 2 :to n
		 :for a = t1 then b
		 :for b = t2 then c
		 :for c = (+ a (* b b))
		 :finally (format t "~a~%" b)))
