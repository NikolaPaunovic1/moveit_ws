;; Auto-generated. Do not edit!


(when (boundp 'my_services::ObjectPositionService)
  (if (not (find-package "MY_SERVICES"))
    (make-package "MY_SERVICES"))
  (shadow 'ObjectPositionService (find-package "MY_SERVICES")))
(unless (find-package "MY_SERVICES::OBJECTPOSITIONSERVICE")
  (make-package "MY_SERVICES::OBJECTPOSITIONSERVICE"))
(unless (find-package "MY_SERVICES::OBJECTPOSITIONSERVICEREQUEST")
  (make-package "MY_SERVICES::OBJECTPOSITIONSERVICEREQUEST"))
(unless (find-package "MY_SERVICES::OBJECTPOSITIONSERVICERESPONSE")
  (make-package "MY_SERVICES::OBJECTPOSITIONSERVICERESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass my_services::ObjectPositionServiceRequest
  :super ros::object
  :slots (_shape_name ))

(defmethod my_services::ObjectPositionServiceRequest
  (:init
   (&key
    ((:shape_name __shape_name) "")
    )
   (send-super :init)
   (setq _shape_name (string __shape_name))
   self)
  (:shape_name
   (&optional __shape_name)
   (if __shape_name (setq _shape_name __shape_name)) _shape_name)
  (:serialization-length
   ()
   (+
    ;; string _shape_name
    4 (length _shape_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _shape_name
       (write-long (length _shape_name) s) (princ _shape_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _shape_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _shape_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass my_services::ObjectPositionServiceResponse
  :super ros::object
  :slots (_object_pose ))

(defmethod my_services::ObjectPositionServiceResponse
  (:init
   (&key
    ((:object_pose __object_pose) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _object_pose __object_pose)
   self)
  (:object_pose
   (&rest __object_pose)
   (if (keywordp (car __object_pose))
       (send* _object_pose __object_pose)
     (progn
       (if __object_pose (setq _object_pose (car __object_pose)))
       _object_pose)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose _object_pose
    (send _object_pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose _object_pose
       (send _object_pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose _object_pose
     (send _object_pose :deserialize buf ptr-) (incf ptr- (send _object_pose :serialization-length))
   ;;
   self)
  )

(defclass my_services::ObjectPositionService
  :super ros::object
  :slots ())

(setf (get my_services::ObjectPositionService :md5sum-) "6d1b74b2e09de95ba7cb8ac42e760730")
(setf (get my_services::ObjectPositionService :datatype-) "my_services/ObjectPositionService")
(setf (get my_services::ObjectPositionService :request) my_services::ObjectPositionServiceRequest)
(setf (get my_services::ObjectPositionService :response) my_services::ObjectPositionServiceResponse)

(defmethod my_services::ObjectPositionServiceRequest
  (:response () (instance my_services::ObjectPositionServiceResponse :init)))

(setf (get my_services::ObjectPositionServiceRequest :md5sum-) "6d1b74b2e09de95ba7cb8ac42e760730")
(setf (get my_services::ObjectPositionServiceRequest :datatype-) "my_services/ObjectPositionServiceRequest")
(setf (get my_services::ObjectPositionServiceRequest :definition-)
      "string shape_name
---
geometry_msgs/Pose object_pose

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

(setf (get my_services::ObjectPositionServiceResponse :md5sum-) "6d1b74b2e09de95ba7cb8ac42e760730")
(setf (get my_services::ObjectPositionServiceResponse :datatype-) "my_services/ObjectPositionServiceResponse")
(setf (get my_services::ObjectPositionServiceResponse :definition-)
      "string shape_name
---
geometry_msgs/Pose object_pose

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



(provide :my_services/ObjectPositionService "6d1b74b2e09de95ba7cb8ac42e760730")


