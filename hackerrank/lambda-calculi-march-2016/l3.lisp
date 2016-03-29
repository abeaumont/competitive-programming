(let* ((sides (loop repeat (read) collect (cons (read) (read))))
       (area (reduce #'+ (mapcar (lambda (x y)
                                   (* (+ (car x) (car y))
                                      (- (cdr x) (cdr y))))
                                 sides
                                 (append (cdr sides) (list (car sides)))))))
  (format t "~a~%" (/ area 2.0)))
  
