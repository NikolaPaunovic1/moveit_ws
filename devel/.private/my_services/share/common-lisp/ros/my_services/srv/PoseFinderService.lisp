; Auto-generated. Do not edit!


(cl:in-package my_services-srv)


;//! \htmlinclude PoseFinderService-request.msg.html

(cl:defclass <PoseFinderService-request> (roslisp-msg-protocol:ros-message)
  ((location
    :reader location
    :initarg :location
    :type cl:string
    :initform "")
   (id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0))
)

(cl:defclass PoseFinderService-request (<PoseFinderService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PoseFinderService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PoseFinderService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-srv:<PoseFinderService-request> is deprecated: use my_services-srv:PoseFinderService-request instead.")))

(cl:ensure-generic-function 'location-val :lambda-list '(m))
(cl:defmethod location-val ((m <PoseFinderService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-srv:location-val is deprecated.  Use my_services-srv:location instead.")
  (location m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <PoseFinderService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-srv:id-val is deprecated.  Use my_services-srv:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PoseFinderService-request>) ostream)
  "Serializes a message object of type '<PoseFinderService-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'location))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'location))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PoseFinderService-request>) istream)
  "Deserializes a message object of type '<PoseFinderService-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'location) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'location) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PoseFinderService-request>)))
  "Returns string type for a service object of type '<PoseFinderService-request>"
  "my_services/PoseFinderServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PoseFinderService-request)))
  "Returns string type for a service object of type 'PoseFinderService-request"
  "my_services/PoseFinderServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PoseFinderService-request>)))
  "Returns md5sum for a message object of type '<PoseFinderService-request>"
  "db8bd25f1ebf7eaf192d38a6e222e58e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PoseFinderService-request)))
  "Returns md5sum for a message object of type 'PoseFinderService-request"
  "db8bd25f1ebf7eaf192d38a6e222e58e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PoseFinderService-request>)))
  "Returns full string definition for message of type '<PoseFinderService-request>"
  (cl:format cl:nil "string location~%uint8 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PoseFinderService-request)))
  "Returns full string definition for message of type 'PoseFinderService-request"
  (cl:format cl:nil "string location~%uint8 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PoseFinderService-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'location))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PoseFinderService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PoseFinderService-request
    (cl:cons ':location (location msg))
    (cl:cons ':id (id msg))
))
;//! \htmlinclude PoseFinderService-response.msg.html

(cl:defclass <PoseFinderService-response> (roslisp-msg-protocol:ros-message)
  ((place_pose
    :reader place_pose
    :initarg :place_pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass PoseFinderService-response (<PoseFinderService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PoseFinderService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PoseFinderService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-srv:<PoseFinderService-response> is deprecated: use my_services-srv:PoseFinderService-response instead.")))

(cl:ensure-generic-function 'place_pose-val :lambda-list '(m))
(cl:defmethod place_pose-val ((m <PoseFinderService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-srv:place_pose-val is deprecated.  Use my_services-srv:place_pose instead.")
  (place_pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PoseFinderService-response>) ostream)
  "Serializes a message object of type '<PoseFinderService-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'place_pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PoseFinderService-response>) istream)
  "Deserializes a message object of type '<PoseFinderService-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'place_pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PoseFinderService-response>)))
  "Returns string type for a service object of type '<PoseFinderService-response>"
  "my_services/PoseFinderServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PoseFinderService-response)))
  "Returns string type for a service object of type 'PoseFinderService-response"
  "my_services/PoseFinderServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PoseFinderService-response>)))
  "Returns md5sum for a message object of type '<PoseFinderService-response>"
  "db8bd25f1ebf7eaf192d38a6e222e58e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PoseFinderService-response)))
  "Returns md5sum for a message object of type 'PoseFinderService-response"
  "db8bd25f1ebf7eaf192d38a6e222e58e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PoseFinderService-response>)))
  "Returns full string definition for message of type '<PoseFinderService-response>"
  (cl:format cl:nil "geometry_msgs/Pose place_pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PoseFinderService-response)))
  "Returns full string definition for message of type 'PoseFinderService-response"
  (cl:format cl:nil "geometry_msgs/Pose place_pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PoseFinderService-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'place_pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PoseFinderService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PoseFinderService-response
    (cl:cons ':place_pose (place_pose msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PoseFinderService)))
  'PoseFinderService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PoseFinderService)))
  'PoseFinderService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PoseFinderService)))
  "Returns string type for a service object of type '<PoseFinderService>"
  "my_services/PoseFinderService")