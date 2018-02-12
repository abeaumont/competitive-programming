;; https://www.codechef.com/FEB18/problems/BROCLK
(defconstant +mod+ (+ (expt 10 9) 7))

(defun chevyshev (n p)
  (loop
     :for i :from 1 :to n
     :for a = 1 :then b
     :for b = p :then tmp
     :for tmp = (mod (- (mod (* 2 p b) +mod+) a) +mod+)
     :finally (return b)))

(defun modinv (a b)
  (do ((r (cons b a) (cons (- (cdr r) (* (car r) q)) (car r)))
       (s (cons 0 1) (cons (- (cdr s) (* (car s) q)) (car s)))
       (u (cons 1 0) (cons (- (cdr u) (* (car u) q)) (car u)))
       (q nil))
      ((zerop (car r)) (cdr s))
    (setq q (floor (/ (cdr r) (car r))))))

(dotimes (_ (read))
  (let* ((l (read))
         (d (read))
         (s (read))
         (c (chevyshev s (* d (modinv l +mod+)))))
    (format t "~a~%" (mod (* l c) +mod+))))
