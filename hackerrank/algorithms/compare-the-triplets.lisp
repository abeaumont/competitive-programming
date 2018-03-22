;; https://www.hackerrank.com/challenges/compare-the-triplets
(defun triplet () (loop :repeat 3 :collect (read)))
(let ((a (triplet))
      (b (triplet)))
  (format t "~a ~a~%" (count t (mapcar #'> a b)) (count t (mapcar #'> b a))))
