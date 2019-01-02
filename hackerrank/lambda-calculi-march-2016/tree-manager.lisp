;; https://www.hackerrank.com/contests/lambda-calculi-march-2016/challenges/tree-manager
(defstruct (node (:constructor new-node (&optional (value 0))))
  (value 0)
  (children (make-array 15 :initial-element nil)))

(defvar *pos* nil)
(defvar *tree* (new-node))

(defun split (string &key (remove-if-empty t))
  (let ((tokens
         (loop for i = 0 then (1+ j)
            as j = (position #\Space string :start i)
            collect (subseq string i j)
            while j)))
    (if remove-if-empty
        (remove nil tokens)
        tokens)))

(defun insert (node pos val)
  (let ((v (node-children node)))
    (loop for i from 13 downto pos
          do (setf (aref v (1+ i)) (aref v i))
          finally (setf (aref v pos) (new-node val)))))

(defun delete-item (node pos)
  (let ((v (node-children node)))
    (loop for i from pos below 14
          for next = (aref v (1+ i))
          while next do (setf (aref v i) next)
          finally (setf (aref v i) nil))))

(defun get-node ()
  (loop for node = *tree* then (aref (node-children node) p)
        for p in (reverse *pos*)
        finally (return node)))

(defun get-parent-node ()
  (loop for node = *tree* then (aref (node-children node) p)
        for p in (reverse (cdr *pos*))
        finally (return node)))
  
(defun change-value (x)
  (setf (node-value (get-node)) x))

(defun print-current ()
  (format t "~a~%" (node-value (get-node))))

(defun visit-left ()
  (setf *pos* (cons (1- (car *pos*)) (cdr *pos*))))

(defun visit-right ()
  (setf *pos* (cons (1+ (car *pos*)) (cdr *pos*))))

(defun visit-parent ()
  (setf *pos* (cdr *pos*)))

(defun visit-child (n)
  (push (1- n) *pos*))

(defun insert-left (x)
  (insert (get-parent-node) (car *pos*) x)
  (visit-right))


(defun insert-right (x)
  (insert (get-parent-node) (1+ (car *pos*)) x))

(defun insert-child (x)
  (insert (get-node) 0 x))

(defun delete-current ()
  (delete-item (get-parent-node) (car *pos*))
  (visit-parent))

(defun parse-line (line)
  (let ((tokens (split line)))
    (cond ((string= (car tokens) "insert")
           (let ((x (parse-integer (caddr tokens))))
             (cond ((string= (cadr tokens) "left") (insert-left x))
                   ((string= (cadr tokens) "right") (insert-right x))
                   (t (insert-child x)))))
          ((string= (car tokens) "visit")
           (cond ((string= (cadr tokens) "left") (visit-left))
                 ((string= (cadr tokens) "right") (visit-right))
                 ((string= (cadr tokens) "parent") (visit-parent))
                 (t (visit-child (parse-integer (caddr tokens))))))
          ((string= (car tokens) "change")
           (change-value (parse-integer (cadr tokens))))
          ((string= (car tokens) "print") (print-current))
          (t (delete-current)))))

(loop repeat (parse-integer (read-line) :junk-allowed t)
      do (parse-line (read-line)))
