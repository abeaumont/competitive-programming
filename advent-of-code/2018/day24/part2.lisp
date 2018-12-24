#!/usr/bin/sbcl --script
(defconstant +immune+ (intern "immune"))
(defconstant +infection+ (intern "infection"))
(defconstant +weak+ (intern "weak"))

(defun group-type-p (type)
  "Is this a group type?"
  (member type (list +immune+ +infection+)))

(deftype group-type ()
  "Type for a unit group."
  '(satisfies group-type-p))

(defstruct (group
            (:constructor new-group
                (type units hit-points attack-damage attack-type
                 initiative weaknesses immunities)))
  "A group of units of either type."
  (type 'immune :type group-type :read-only t)
  (units 0 :type fixnum)
  (hit-points 0 :type fixnum :read-only t)
  (attack-damage 0 :type fixnum)
  (attack-type 'fire :type symbol :read-only t)
  (initiative 0 :type fixnum :read-only t)
  (weaknesses nil :type list :read-only t)
  (immunities nil :type list :read-only t))

(defun group-effective-power (group)
  "Effective power of a group."
  (* (group-units group) (group-attack-damage group)))

(defun group-greaterp (group1 group2)
  "Check if first group is greater than second group"
  (cond ((> (group-effective-power group1) (group-effective-power group2)) t)
        ((< (group-effective-power group1) (group-effective-power group2)) nil)
        (t (> (group-initiative group1) (group-initiative group2)))))

(defun damage (attacker target)
  "Damage generate by an attacker to a target"
  (cond
    ((null target) 0)
    ((eq (group-type attacker) (group-type target)) 0)
    ((member (group-attack-type attacker) (group-immunities target)) 0)
    ((member (group-attack-type attacker) (group-weaknesses target))
     (* 2 (group-effective-power attacker)))
    (t (group-effective-power attacker))))

(defun choose-target (attacker groups)
  "Choose the target based on damage, effective power and initiative."
  (let* ((type (group-type attacker))
         (attack-type (group-attack-type attacker))
         (groups (remove type groups :key #'group-type)))
    (labels ((max-target (target1 target2)
               (let ((damage1 (damage attacker target1))
                     (damage2 (damage attacker target2)))
                 (cond ((> damage1 damage2) target1)
                       ((< damage1 damage2) target2)
                       ((zerop damage1) nil)
                       (t (let ((power1 (group-effective-power target1))
                                (power2 (group-effective-power target2))
                                (initiative1 (group-initiative target1))
                                (initiative2 (group-initiative target2)))
                            (cond ((> power1 power2) target1)
                                  ((< power1 power2) target2)
                                  ((> initiative1 initiative2) target1)
                                  (t target2))))))))
      (reduce #'max-target groups :initial-value nil))))

(defun choose-targets (groups)
  "Select targets for each group"
  (labels ((iter (groups targets pairs)
             (if (null groups)
                 pairs
                 (let* ((group (car groups))
                        (target (choose-target group targets)))
                   (iter (cdr groups)
                         (remove target targets :test #'equalp)
                         (cons (cons group target) pairs))))))
    (iter (sort (copy-list groups) #'group-greaterp) groups nil)))

(defun attack-target (attacker target)
  "Attack a target if there are units left. Modifies target."
  (when (and target (not (zerop (group-units attacker))))
    (let ((hit-units (floor (damage attacker target) (group-hit-points target))))
      (unless (zerop hit-units)
        (decf (group-units target) (min hit-units (group-units target)))))))

(defun attack-targets (group-pairs)
  "Attack each target from each group."
  (labels ((iter (prs change groups)
             (if (null prs)
                 (and change groups)
                 (let ((pr (car prs)))
                   (iter (cdr prs)
                         (if (attack-target (car pr) (cdr pr)) t change)
                         (cons (car pr) groups))))))
    (let ((pairs (sort group-pairs #'>
                       :key (lambda (pr) (group-initiative (car pr))))))
      (iter pairs nil nil))))

(defun finish-p (groups)
  "Is the fight over?"
  (null (cdr (remove-duplicates groups :key #'group-type))))

(defun score (groups)
  "Fight score (survival units), null if immune system losses."
  (when (and groups (eq (group-type (car groups)) +immune+))
    (reduce #'+ groups :key #'group-units)))

(defun fight (groups)
  "Fight till only a team survives, return the amount of surviving units."
  (if (finish-p groups)
      (score groups)
      (let ((groups (attack-targets (choose-targets groups))))
        (fight (remove 0 groups :key #'group-units)))))

(defun boosted-fight (groups boost)
  "Fight with boosted attack damage."
  (dolist (g groups)
    (when (eq (group-type g) +immune+)
      (incf (group-attack-damage g) boost)))
  (fight groups))

(defun binary-search (predicate low high)
  "Binary search over a range with function application."
  (if (= low high)
      (funcall predicate low)
      (let* ((middle (ash (+ low high) -1)))
        (if (funcall predicate middle)
            (binary-search predicate low middle)
            (binary-search predicate (1+ middle) high)))))

(defun split (sequence &optional (item #\Space))
  "Split a sequence by item."
  (loop :for i = 0 :then (1+ j)
        :as j = (or (position item sequence :start i))
        :unless (eq i j)
          :collect (subseq sequence i j)
        :while j))

(defun trim (sequence &key (item #\Space) (test #'eql))
  "Remove a item from beginning or end of the sequence"
  (labels ((item-p (x) (funcall test x item)))
    (subseq sequence
            (position-if-not #'item-p sequence)
            (1+ (position-if-not #'item-p sequence :from-end t)))))

(defun parse-option (string)
  "Parse a group immunity / weakness."
  (let ((items (split string)))
    (cons (intern (car items))
          (mapcar (lambda (x) (intern (trim x :item #\,)))
                  (cddr items)))))

(defun parse-group-options (string)
  "Parse all group immunities / weaknesses."
  (let* ((assoc (mapcar #'parse-option (split string #\;)))
         (weaknesses (mapcan #'cdr (remove +immune+ assoc :key #'car)))
         (immunities (mapcan #'cdr (remove +weak+ assoc :key #'car))))
    (values weaknesses immunities)))

(defun parse-group-mandatory (string type weaknesses immunities)
  "Parse the mandatory group data."
  (let ((items (split string)))
    (new-group type
               (parse-integer (nth 0 items))
               (parse-integer (nth 4 items))
               (parse-integer (nth 12 items))
               (intern (nth 13 items))
               (parse-integer (nth 17 items))
               weaknesses immunities)))

(defun parse-group (string type)
  "Parse a group."
  (let ((items (split string #\()))
    (if (null (cdr items))
        (parse-group-mandatory (car items) type nil nil)
        (let ((items2 (split (cadr items) #\))))
          (multiple-value-call #'parse-group-mandatory
            (funcall #'concatenate 'string (car items) (cadr items2))
            type
            (parse-group-options (car items2)))))))

(defun parse-groups ()
  "Parse all the groups."
  (labels ((iter (type groups)
             (let ((line (read-line *standard-input* nil 'eof)))
               (if (or (eq line 'eof) (zerop (length line)))
                   groups
                   (iter type (cons (parse-group line type) groups))))))
    (let* ((type (intern (string-downcase (car (split (read-line))))))
           (groups (iter type nil))
           (type (intern (string-downcase (trim (read-line) :item #\:)))))
      (iter type groups))))

(let ((groups (parse-groups)))
  (labels ((fight (boost)
             (boosted-fight (mapcar #'copy-group groups) boost)))
    (format t "~a~%" (binary-search #'fight 0 (expt 2 60)))))
