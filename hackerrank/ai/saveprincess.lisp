;; https://www.hackerrank.com/challenges/saveprincess
(defun read-number ()
  (parse-integer (read-line)))

(defun read-map (size)
  (let (p m)
    (dotimes (i size)
      (let ((line (read-line)))
        (dotimes (j size)
          (case (schar line j)
            ((#\m) (setf m (cons j i)))
            ((#\p) (setf p (cons j i)))))))
    (values p m)))

(defun reduce-map (reduce map &rest items)
  (reduce reduce (mapcar map items)))

(defun print-walk (n l r)
  (dotimes (i (abs n))
    (format t "~a~%" (if (> n 0) l r))))

(defun walk (p m)
  (destructuring-bind (x y) (mapcar (lambda (fn)
                                      (reduce-map #'- fn p m))
                                    '(car cdr))
    (mapc #'print-walk (list x y) '(right down) '(left up))))

(defun main ()
  (multiple-value-call #'walk (read-map (read-number))))

(main)
