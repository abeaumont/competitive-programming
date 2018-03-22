;; https://www.hackerrank.com/challenges/library-fine
(let ((ad (read)) (am (read)) (ay (read))
      (ed (read)) (em (read)) (ey (read)))
  (write (cond ((> ay ey) 10000)
               ((< ay ey) 0)
               ((> am em) (* 500 (- am em)))
               ((< am em) 0)
               ((> ad ed) (* 15 (- ad ed)))
               (t 0))))
