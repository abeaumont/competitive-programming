;; https://www.hackerrank.com/challenges/utopian-tree
(defun trees (n) (- (expt 2 (1+ (floor n 2))) (if (evenp n) 2 1)))
(loop repeat (read) do (format t "~a~%" (trees (1+ (read)))))
