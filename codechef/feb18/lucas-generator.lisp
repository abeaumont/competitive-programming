(let ((xs (loop :for i :from 0 :to 20 :collecting (cons i 5))))
  (format t "~a~%" (length xs))
  (dolist (x xs)
    (format t "~a ~a~%" (car x) (cdr x))))
