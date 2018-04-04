;; https://abc044.contest.atcoder.jp/tasks/arc060_a
(defvar *b*)
(defvar *cache*)
(defvar *x*)

(defun binomial (n)
  (setf *b* (make-array (list n n)))
  (dotimes (i n)
    (setf (aref *b* 0 i) 0)
    (setf (aref *b* i i) 1))
  (loop :for i :from 1 :below n :do
     (loop :for j :from 1 :below i :do
        (setf (aref *b* i j) (+ (aref *b* (1- i) (1- j)) (aref *b* (1- i) j))))))

(defun s (a k i)
  (cond ((< a 0) 0)
        ((< k 0) 0)
        ((zerop k) (if (zerop a) 1 0))
        ((> i a) 0)
        ((= i 51) 0)
        (t (let ((key (+ (* a 51 51) (* k 51) i)))
             (if (aref *cache* key)
                 (aref *cache* key)
                 (let ((c (s a k (1+ i))))
                   (loop :for j :from 1 :to (aref *x* i) :do
                      (incf c (* (aref *b* (1+ (aref *x* i)) (1+ j))
                                 (s (- a (* i j)) (- k j) (1+ i)))))
                   (setf (aref *cache* key) c)
                   c))))))

(let ((n (read))
      (a (read)))
  (binomial (+ n 2))
  (setf *cache* (make-array (expt 51 4) :initial-element nil))
  (setf *x* (make-array 51 :initial-element 0))
  (loop :repeat n :do (incf (aref *x* (read))))
  (format t "~a~%" (loop :for i :from 1 :to n :sum (s (* a i) i 0))))
