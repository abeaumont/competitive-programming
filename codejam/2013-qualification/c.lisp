;; https://code.google.com/codejam/contest/2270488/dashboard#s=p2
(defun split (string)
  (loop for i = 0 then (1+ j)
     as j = (position #\Space string :start i)
     collect (subseq string i j)
     while j))

(defun fair-and-square-p (n)
  (every #'identity (mapcar (lambda (i)
                              (let ((s (write-to-string i)))
                                (equal s (reverse s))))
                            (list n (* n n)))))

(defun fair-and-squares ()
  (let ((limits (mapcar (lambda (n) (sqrt (coerce (parse-integer n) 'double-float))) (split (read-line)))))
    (loop for i from (ceiling (first limits)) to (floor (second limits))
       count (fair-and-square-p i))))

(dotimes (i (parse-integer (read-line)))
  (format t "Case #~a: ~a~%" (1+ i) (fair-and-squares)))
