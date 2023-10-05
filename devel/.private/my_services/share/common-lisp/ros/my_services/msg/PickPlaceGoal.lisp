; Auto-generated. Do not edit!


(cl:in-package my_services-msg)


;//! \htmlinclude PickPlaceGoal.msg.html

(cl:defclass <PickPlaceGoal> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (pose
    :reader pose
    :initarg :pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass PickPlaceGoal (<PickPlaceGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PickPlaceGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PickPlaceGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-msg:<PickPlaceGoal> is deprecated: use my_services-msg:PickPlaceGoal instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <PickPlaceGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-msg:id-val is deprecated.  Use my_services-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <PickPlaceGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-msg:pose-val is deprecated.  Use my_services-msg:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PickPlaceGoal>) ostream)
  "Serializes a message object of type '<PickPlaceGoal>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PickPlaceGoal>) istream)
  "Deserializes a message object of type '<PickPlaceGoal>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PickPlaceGoal>)))
  "Returns string type for a message object of type '<PickPlaceGoal>"
  "my_services/PickPlaceGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PickPlaceGoal)))
  "Returns string type for a message object of type 'PickPlaceGoal"
  "my_services/PickPlaceGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PickPlaceGoal>)))
  "Returns md5sum for a message object of type '<PickPlaceGoal>"
  "496d91d6f8c51d776c1feee502f9e9ff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PickPlaceGoal)))
  "Returns md5sum for a message object of type 'PickPlaceGoal"
  "496d91d6f8c51d776c1feee502f9e9ff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PickPlaceGoal>)))
  "Returns full string definition for message of type '<PickPlaceGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%uint8 id~%geometry_msgs/Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PickPlaceGoal)))
  "Returns full string definition for message of type 'PickPlaceGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%uint8 id~%geometry_msgs/Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PickPlaceGoal>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PickPlaceGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'PickPlaceGoal
    (cl:cons ':id (id msg))
    (cl:cons ':pose (pose msg))
))
