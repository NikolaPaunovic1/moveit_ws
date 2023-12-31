;; Auto-generated. Do not edit!


(when (boundp 'my_services::PickPlace2Goal)
  (if (not (find-package "MY_SERVICES"))
    (make-package "MY_SERVICES"))
  (shadow 'PickPlace2Goal (find-package "MY_SERVICES")))
(unless (find-package "MY_SERVICES::PICKPLACE2GOAL")
  (make-package "MY_SERVICES::PICKPLACE2GOAL"))

(in-package "ROS")
;;//! \htmlinclude PickPlace2Goal.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass my_services::PickPlace2Goal
  :super ros::object
  :slots (_id _pose _location ))

(defmethod my_services::PickPlace2Goal
  (:init
   (&key
    ((:id __id) 0)
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    ((:location __location) "")
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _pose __pose)
   (setq _location (string __location))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:location
   (&optional __location)
   (if __location (setq _location __location)) _location)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ;; string _location
    4 (length _location)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;; string _location
       (write-long (length _location) s) (princ _location s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; string _location
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _location (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get my_services::PickPlace2Goal :md5sum-) "294d86574595b4f78b89451d18b8a490")
(setf (get my_services::PickPlace2Goal :datatype-) "my_services/PickPlace2Goal")
(setf (get my_services::PickPlace2Goal :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#goal definition
uint8 id
geometry_msgs/Pose pose
string location

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :my_services/PickPlace2Goal "294d86574595b4f78b89451d18b8a490")


