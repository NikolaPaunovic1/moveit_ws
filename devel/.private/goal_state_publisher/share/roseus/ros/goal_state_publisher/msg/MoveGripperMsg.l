;; Auto-generated. Do not edit!


(when (boundp 'goal_state_publisher::MoveGripperMsg)
  (if (not (find-package "GOAL_STATE_PUBLISHER"))
    (make-package "GOAL_STATE_PUBLISHER"))
  (shadow 'MoveGripperMsg (find-package "GOAL_STATE_PUBLISHER")))
(unless (find-package "GOAL_STATE_PUBLISHER::MOVEGRIPPERMSG")
  (make-package "GOAL_STATE_PUBLISHER::MOVEGRIPPERMSG"))

(in-package "ROS")
;;//! \htmlinclude MoveGripperMsg.msg.html


(defclass goal_state_publisher::MoveGripperMsg
  :super ros::object
  :slots (_width _speed ))

(defmethod goal_state_publisher::MoveGripperMsg
  (:init
   (&key
    ((:width __width) 0.0)
    ((:speed __speed) 0.0)
    )
   (send-super :init)
   (setq _width (float __width))
   (setq _speed (float __speed))
   self)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; float64 _width
    8
    ;; float64 _speed
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _width
       (sys::poke _width (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _width
     (setq _width (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _speed
     (setq _speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get goal_state_publisher::MoveGripperMsg :md5sum-) "d16050a0fe85f1c2cb8347c99678362e")
(setf (get goal_state_publisher::MoveGripperMsg :datatype-) "goal_state_publisher/MoveGripperMsg")
(setf (get goal_state_publisher::MoveGripperMsg :definition-)
      "# A custom message type for sending commands to a Franka gripper
# Define the message fields
float64 width
float64 speed


")



(provide :goal_state_publisher/MoveGripperMsg "d16050a0fe85f1c2cb8347c99678362e")


