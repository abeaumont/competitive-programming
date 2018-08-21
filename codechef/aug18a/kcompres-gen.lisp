#!/usr/bin/sbcl --script
(defparameter *t* 3)
(defparameter *n* (expt 10 4))
(defparameter *s* (expt 10 9))
(defparameter *a* (1+ (expt 10 9)))

(setf *random-state* (make-random-state t))

(let ((tt (1+ (random *t*))))
  (format t "~a~%" tt)
  (loop
     :repeat tt
     :do (let* ((n (1+ (random *n*)))
                (s (1+ (random *s*)))
                (a (loop :repeat n :collect (random *a*))))
           (format t "~a ~a~%" n s)
           (format t "~{~a~^ ~}~%" a))))
