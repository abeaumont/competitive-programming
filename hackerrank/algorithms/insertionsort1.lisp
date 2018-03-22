;; https://www.hackerrank.com/challenges/insertionsort1
(defun read-list ()
    (let ((n (read *standard-input* nil)))
        (if (null n)
            nil
            (cons n (read-list)))))

(defun print-vector (v)
  (let ((s (length v)))
    (loop for i from 0 below (1- s)
       do (format t "~a " (aref v i))
       finally (format t "~a~%" (aref v (1- s))))))

(defun insertion-sort (item vector)
  (loop for i from (1- (length vector)) downto 1
     while (> (aref vector (1- i)) item)
     do (setf (aref vector i) (aref vector (1- i))) (print-vector vector)
     finally (setf (aref vector i) item) (print-vector vector)))

(let* ((size (read))
       (vector (make-array size :element-type 'fixnum :initial-contents (read-list))))
  (insertion-sort (aref vector (1- size)) vector))
