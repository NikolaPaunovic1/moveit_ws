;; Auto-generated. Do not edit!


(when (boundp 'my_services::PickPlace2Feedback)
  (if (not (find-package "MY_SERVICES"))
    (make-package "MY_SERVICES"))
  (shadow 'PickPlace2Feedback (find-package "MY_SERVICES")))
(unless (find-package "MY_SERVICES::PICKPLACE2FEEDBACK")
  (make-package "MY_SERVICES::PICKPLACE2FEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude PickPlace2Feedback.msg.html


(defclass my_services::PickPlace2Feedback
  :super ros::object
  :slots (_info ))

(defmethod my_services::PickPlace2Feedback
  (:init
   (&key
    ((:info __info) "")
    )
   (send-super :init)
   (setq _info (string __info))
   self)
  (:info
   (&optional __info)
   (if __info (setq _info __info)) _info)
  (:serialization-length
   ()
   (+
    ;; string _info
    4 (length _info)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _info
       (write-long (length _info) s) (princ _info s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _info
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _info (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get my_services::PickPlace2Feedback :md5sum-) "c10fc26d5cca9a4b9114f5fc5dea9570")
(setf (get my_services::PickPlace2Feedback :datatype-) "my_services/PickPlace2Feedback")
(setf (get my_services::PickPlace2Feedback :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#feedback
string info


")



(provide :my_services/PickPlace2Feedback "c10fc26d5cca9a4b9114f5fc5dea9570")

