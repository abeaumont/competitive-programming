;; https://open.kattis.com/problems/catalansquare
(defun c (n)
	(loop
		 :for a = 1 :then (* a i)
		 :for b = 1 :then (* b j)
		 :for i :from 1 :to n
		 :for j :from (1+ n) :to (* 2 n)
		 :finally (return (/ b a (1+ n)))))

(format t "~a~%" (c (1+ (read))))
