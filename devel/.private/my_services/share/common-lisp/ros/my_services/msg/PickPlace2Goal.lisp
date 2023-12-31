; Auto-generated. Do not edit!


(cl:in-package my_services-msg)


;//! \htmlinclude PickPlace2Goal.msg.html

(cl:defclass <PickPlace2Goal> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (pose
    :reader pose
    :initarg :pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (location
    :reader location
    :initarg :location
    :type cl:string
    :initform ""))
)

(cl:defclass PickPlace2Goal (<PickPlace2Goal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PickPlace2Goal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PickPlace2Goal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-msg:<PickPlace2Goal> is deprecated: use my_services-msg:PickPlace2Goal instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <PickPlace2Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-msg:id-val is deprecated.  Use my_services-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <PickPlace2Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-msg:pose-val is deprecated.  Use my_services-msg:pose instead.")
  (pose m))

(cl:ensure-generic-function 'location-val :lambda-list '(m))
(cl:defmethod location-val ((m <PickPlace2Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-msg:location-val is deprecated.  Use my_services-msg:location instead.")
  (location m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PickPlace2Goal>) ostream)
  "Serializes a message object of type '<PickPlace2Goal>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'location))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'location))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PickPlace2Goal>) istream)
  "Deserializes a message object of type '<PickPlace2Goal>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'location) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'location) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PickPlace2Goal>)))
  "Returns string type for a message object of type '<PickPlace2Goal>"
  "my_services/PickPlace2Goal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PickPlace2Goal)))
  "Returns string type for a message object of type 'PickPlace2Goal"
  "my_services/PickPlace2Goal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PickPlace2Goal>)))
  "Returns md5sum for a message object of type '<PickPlace2Goal>"
  "294d86574595b4f78b89451d18b8a490")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PickPlace2Goal)))
  "Returns md5sum for a message object of type 'PickPlace2Goal"
  "294d86574595b4f78b89451d18b8a490")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PickPlace2Goal>)))
  "Returns full string definition for message of type '<PickPlace2Goal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%uint8 id~%geometry_msgs/Pose pose~%string location~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PickPlace2Goal)))
  "Returns full string definition for message of type 'PickPlace2Goal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%uint8 id~%geometry_msgs/Pose pose~%string location~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PickPlace2Goal>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
     4 (cl:length (cl:slot-value msg 'location))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PickPlace2Goal>))
  "Converts a ROS message object to a list"
  (cl:list 'PickPlace2Goal
    (cl:cons ':id (id msg))
    (cl:cons ':pose (pose msg))
    (cl:cons ':location (location msg))
))
