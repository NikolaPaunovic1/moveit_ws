;; Auto-generated. Do not edit!


(when (boundp 'my_services::PoseFinderService)
  (if (not (find-package "MY_SERVICES"))
    (make-package "MY_SERVICES"))
  (shadow 'PoseFinderService (find-package "MY_SERVICES")))
(unless (find-package "MY_SERVICES::POSEFINDERSERVICE")
  (make-package "MY_SERVICES::POSEFINDERSERVICE"))
(unless (find-package "MY_SERVICES::POSEFINDERSERVICEREQUEST")
  (make-package "MY_SERVICES::POSEFINDERSERVICEREQUEST"))
(unless (find-package "MY_SERVICES::POSEFINDERSERVICERESPONSE")
  (make-package "MY_SERVICES::POSEFINDERSERVICERESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass my_services::PoseFinderServiceRequest
  :super ros::object
  :slots (_location _id ))

(defmethod my_services::PoseFinderServiceRequest
  (:init
   (&key
    ((:location __location) "")
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _location (string __location))
   (setq _id (round __id))
   self)
  (:location
   (&optional __location)
   (if __location (setq _location __location)) _location)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; string _location
    4 (length _location)
    ;; uint8 _id
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _location
       (write-long (length _location) s) (princ _location s)
     ;; uint8 _id
       (write-byte _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _location
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _location (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass my_services::PoseFinderServiceResponse
  :super ros::object
  :slots (_place_pose ))

(defmethod my_services::PoseFinderServiceResponse
  (:init
   (&key
    ((:place_pose __place_pose) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _place_pose __place_pose)
   self)
  (:place_pose
   (&rest __place_pose)
   (if (keywordp (car __place_pose))
       (send* _place_pose __place_pose)
     (progn
       (if __place_pose (setq _place_pose (car __place_pose)))
       _place_pose)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose _place_pose
    (send _place_pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose _place_pose
       (send _place_pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose _place_pose
     (send _place_pose :deserialize buf ptr-) (incf ptr- (send _place_pose :serialization-length))
   ;;
   self)
  )

(defclass my_services::PoseFinderService
  :super ros::object
  :slots ())

(setf (get my_services::PoseFinderService :md5sum-) "db8bd25f1ebf7eaf192d38a6e222e58e")
(setf (get my_services::PoseFinderService :datatype-) "my_services/PoseFinderService")
(setf (get my_services::PoseFinderService :request) my_services::PoseFinderServiceRequest)
(setf (get my_services::PoseFinderService :response) my_services::PoseFinderServiceResponse)

(defmethod my_services::PoseFinderServiceRequest
  (:response () (instance my_services::PoseFinderServiceResponse :init)))

(setf (get my_services::PoseFinderServiceRequest :md5sum-) "db8bd25f1ebf7eaf192d38a6e222e58e")
(setf (get my_services::PoseFinderServiceRequest :datatype-) "my_services/PoseFinderServiceRequest")
(setf (get my_services::PoseFinderServiceRequest :definition-)
      "string location
uint8 id
---
geometry_msgs/Pose place_pose

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

(setf (get my_services::PoseFinderServiceResponse :md5sum-) "db8bd25f1ebf7eaf192d38a6e222e58e")
(setf (get my_services::PoseFinderServiceResponse :datatype-) "my_services/PoseFinderServiceResponse")
(setf (get my_services::PoseFinderServiceResponse :definition-)
      "string location
uint8 id
---
geometry_msgs/Pose place_pose

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



(provide :my_services/PoseFinderService "db8bd25f1ebf7eaf192d38a6e222e58e")


