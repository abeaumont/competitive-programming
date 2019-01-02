;; https://www.hackerrank.com/contests/lambda-calculi-march-2016/challenges/functions-or-not
(defun function-p ()
  (let ((pairs (loop repeat (read) collect (cons (read) (read)))))
    (= (length pairs) (length (remove-duplicates pairs :key #'car)))))

(loop repeat (read) do (format t "~a~%" (if (function-p) "YES" "NO")))
