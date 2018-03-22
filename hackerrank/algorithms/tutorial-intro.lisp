;; https://www.hackerrank.com/challenges/tutorial-intro
(defun read-list ()
    (let ((n (read *standard-input* nil)))
        (if (null n)
            nil
            (cons n (read-list)))))
(let ((value (read))
      (size (read)))
  (prin1 (position value (read-list))))
