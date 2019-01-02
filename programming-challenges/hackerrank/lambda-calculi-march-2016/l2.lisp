(defun function-p ()
  (let ((pairs (loop repeat (read) collect (cons (read) (read)))))
    (= (length pairs) (length (remove-duplicates pairs :key #'car)))))

(loop repeat (read) do (format t "~a~%" (if (function-p) "YES" "NO")))
