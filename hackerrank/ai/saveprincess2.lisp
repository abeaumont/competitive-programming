;; https://www.hackerrank.com/challenges/saveprincess2
(defun read-number ()
  (parse-integer (read-line)))

(defun read-map (size)
  (read-line) ; ignore second line
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

(defun walk (p m)
  (destructuring-bind (x y) (mapcar (lambda (fn)
                                      (reduce-map #'- fn p m))
                                    '(car cdr))
    (mapc #'print-walk (list x y) '(right down) '(left up))))

(defun main ()
  (defun print-walk (n l r)
    (dotimes (i (abs n))
      (format t "~a~%" (if (> n 0) l r))
      (return-from main)))

  (multiple-value-call #'walk (read-map (read-number))))

(main)
