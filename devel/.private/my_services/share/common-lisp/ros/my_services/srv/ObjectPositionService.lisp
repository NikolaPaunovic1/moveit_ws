; Auto-generated. Do not edit!


(cl:in-package my_services-srv)


;//! \htmlinclude ObjectPositionService-request.msg.html

(cl:defclass <ObjectPositionService-request> (roslisp-msg-protocol:ros-message)
  ((shape_name
    :reader shape_name
    :initarg :shape_name
    :type cl:string
    :initform ""))
)

(cl:defclass ObjectPositionService-request (<ObjectPositionService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObjectPositionService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObjectPositionService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-srv:<ObjectPositionService-request> is deprecated: use my_services-srv:ObjectPositionService-request instead.")))

(cl:ensure-generic-function 'shape_name-val :lambda-list '(m))
(cl:defmethod shape_name-val ((m <ObjectPositionService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-srv:shape_name-val is deprecated.  Use my_services-srv:shape_name instead.")
  (shape_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObjectPositionService-request>) ostream)
  "Serializes a message object of type '<ObjectPositionService-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'shape_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'shape_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObjectPositionService-request>) istream)
  "Deserializes a message object of type '<ObjectPositionService-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'shape_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'shape_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObjectPositionService-request>)))
  "Returns string type for a service object of type '<ObjectPositionService-request>"
  "my_services/ObjectPositionServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObjectPositionService-request)))
  "Returns string type for a service object of type 'ObjectPositionService-request"
  "my_services/ObjectPositionServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObjectPositionService-request>)))
  "Returns md5sum for a message object of type '<ObjectPositionService-request>"
  "6d1b74b2e09de95ba7cb8ac42e760730")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObjectPositionService-request)))
  "Returns md5sum for a message object of type 'ObjectPositionService-request"
  "6d1b74b2e09de95ba7cb8ac42e760730")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObjectPositionService-request>)))
  "Returns full string definition for message of type '<ObjectPositionService-request>"
  (cl:format cl:nil "string shape_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObjectPositionService-request)))
  "Returns full string definition for message of type 'ObjectPositionService-request"
  (cl:format cl:nil "string shape_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObjectPositionService-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'shape_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObjectPositionService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ObjectPositionService-request
    (cl:cons ':shape_name (shape_name msg))
))
;//! \htmlinclude ObjectPositionService-response.msg.html

(cl:defclass <ObjectPositionService-response> (roslisp-msg-protocol:ros-message)
  ((object_pose
    :reader object_pose
    :initarg :object_pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass ObjectPositionService-response (<ObjectPositionService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObjectPositionService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObjectPositionService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-srv:<ObjectPositionService-response> is deprecated: use my_services-srv:ObjectPositionService-response instead.")))

(cl:ensure-generic-function 'object_pose-val :lambda-list '(m))
(cl:defmethod object_pose-val ((m <ObjectPositionService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-srv:object_pose-val is deprecated.  Use my_services-srv:object_pose instead.")
  (object_pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObjectPositionService-response>) ostream)
  "Serializes a message object of type '<ObjectPositionService-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'object_pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObjectPositionService-response>) istream)
  "Deserializes a message object of type '<ObjectPositionService-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'object_pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObjectPositionService-response>)))
  "Returns string type for a service object of type '<ObjectPositionService-response>"
  "my_services/ObjectPositionServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObjectPositionService-response)))
  "Returns string type for a service object of type 'ObjectPositionService-response"
  "my_services/ObjectPositionServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObjectPositionService-response>)))
  "Returns md5sum for a message object of type '<ObjectPositionService-response>"
  "6d1b74b2e09de95ba7cb8ac42e760730")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObjectPositionService-response)))
  "Returns md5sum for a message object of type 'ObjectPositionService-response"
  "6d1b74b2e09de95ba7cb8ac42e760730")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObjectPositionService-response>)))
  "Returns full string definition for message of type '<ObjectPositionService-response>"
  (cl:format cl:nil "geometry_msgs/Pose object_pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObjectPositionService-response)))
  "Returns full string definition for message of type 'ObjectPositionService-response"
  (cl:format cl:nil "geometry_msgs/Pose object_pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObjectPositionService-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'object_pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObjectPositionService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ObjectPositionService-response
    (cl:cons ':object_pose (object_pose msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ObjectPositionService)))
  'ObjectPositionService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ObjectPositionService)))
  'ObjectPositionService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObjectPositionService)))
  "Returns string type for a service object of type '<ObjectPositionService>"
  "my_services/ObjectPositionService")