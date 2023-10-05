;; Auto-generated. Do not edit!


(when (boundp 'goal_state_publisher::GraspMsg)
  (if (not (find-package "GOAL_STATE_PUBLISHER"))
    (make-package "GOAL_STATE_PUBLISHER"))
  (shadow 'GraspMsg (find-package "GOAL_STATE_PUBLISHER")))
(unless (find-package "GOAL_STATE_PUBLISHER::GRASPMSG")
  (make-package "GOAL_STATE_PUBLISHER::GRASPMSG"))

(in-package "ROS")
;;//! \htmlinclude GraspMsg.msg.html


(defclass goal_state_publisher::GraspMsg
  :super ros::object
  :slots (_width _speed _force _tolerance ))

(defmethod goal_state_publisher::GraspMsg
  (:init
   (&key
    ((:width __width) 0.0)
    ((:speed __speed) 0.0)
    ((:force __force) 0.0)
    ((:tolerance __tolerance) 0.0)
    )
   (send-super :init)
   (setq _width (float __width))
   (setq _speed (float __speed))
   (setq _force (float __force))
   (setq _tolerance (float __tolerance))
   self)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:force
   (&optional __force)
   (if __force (setq _force __force)) _force)
  (:tolerance
   (&optional __tolerance)
   (if __tolerance (setq _tolerance __tolerance)) _tolerance)
  (:serialization-length
   ()
   (+
    ;; float64 _width
    8
    ;; float64 _speed
    8
    ;; float64 _force
    8
    ;; float64 _tolerance
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
     ;; float64 _force
       (sys::poke _force (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _tolerance
       (sys::poke _tolerance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _width
     (setq _width (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _speed
     (setq _speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _force
     (setq _force (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _tolerance
     (setq _tolerance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get goal_state_publisher::GraspMsg :md5sum-) "b2d8d59c2ef5005c4a7ec11a7cb27855")
(setf (get goal_state_publisher::GraspMsg :datatype-) "goal_state_publisher/GraspMsg")
(setf (get goal_state_publisher::GraspMsg :definition-)
      "# A custom message type for sending commands to a Franka gripper
# Define the message fields
float64 width
float64 speed
float64 force
float64 tolerance

")



(provide :goal_state_publisher/GraspMsg "b2d8d59c2ef5005c4a7ec11a7cb27855")


