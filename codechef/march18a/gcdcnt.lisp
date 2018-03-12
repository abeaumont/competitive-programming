(let* ((n (read))
			 (a (make-array n :initial-contents (loop :repeat n :collect (read))))
			 (q (read)))
	(loop :repeat q :do
		 (case (read)
			 (1 (setf (aref a (1- (read))) (read)))
			 (2 (let ((l (1- (read)))
								(r (1- (read)))
								(g (read)))
						(format t "~a~%" (loop :for i :from l :to r
																:count (= (gcd (aref a i) g) 1))))))))
