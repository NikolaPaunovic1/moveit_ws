;; Auto-generated. Do not edit!


(when (boundp 'goal_state_publisher::StopGripperMsg)
  (if (not (find-package "GOAL_STATE_PUBLISHER"))
    (make-package "GOAL_STATE_PUBLISHER"))
  (shadow 'StopGripperMsg (find-package "GOAL_STATE_PUBLISHER")))
(unless (find-package "GOAL_STATE_PUBLISHER::STOPGRIPPERMSG")
  (make-package "GOAL_STATE_PUBLISHER::STOPGRIPPERMSG"))

(in-package "ROS")
;;//! \htmlinclude StopGripperMsg.msg.html


(defclass goal_state_publisher::StopGripperMsg
  :super ros::object
  :slots (_isStop ))

(defmethod goal_state_publisher::StopGripperMsg
  (:init
   (&key
    ((:isStop __isStop) nil)
    )
   (send-super :init)
   (setq _isStop __isStop)
   self)
  (:isStop
   (&optional (__isStop :null))
   (if (not (eq __isStop :null)) (setq _isStop __isStop)) _isStop)
  (:serialization-length
   ()
   (+
    ;; bool _isStop
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isStop
       (if _isStop (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isStop
     (setq _isStop (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get goal_state_publisher::StopGripperMsg :md5sum-) "4e622c3bf7f741ad63c7902f5596d407")
(setf (get goal_state_publisher::StopGripperMsg :datatype-) "goal_state_publisher/StopGripperMsg")
(setf (get goal_state_publisher::StopGripperMsg :definition-)
      "# A custom message type for sending commands to a Franka gripper
# Define the message fields
bool isStop
")



(provide :goal_state_publisher/StopGripperMsg "4e622c3bf7f741ad63c7902f5596d407")


