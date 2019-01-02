(let ((sides (loop repeat (read) collect (cons (read) (read)))))
  (format t "~a~%"
         (reduce #'+ (mapcar (lambda (x y)
                               (sqrt
                                (+ (expt (- (car x) (car y)) 2)
                                   (expt (- (cdr y) (cdr x)) 2))))
                             sides
                             (append (cdr sides) (list (car sides)))))))
