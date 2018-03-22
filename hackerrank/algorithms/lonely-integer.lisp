;; https://www.hackerrank.com/challenges/lonely-integer
(defun read-list ()
    (let ((n (read *standard-input* nil)))
        (if (null n)
            nil
            (cons n (read-list)))))

(let* ((n (read))
       (l (read-list))
       (s (remove-duplicates l)))
  (loop for i in s
     while (= 2 (count i l))
     finally (prin1 i)))
