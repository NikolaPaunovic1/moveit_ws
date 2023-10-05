; Auto-generated. Do not edit!


(cl:in-package goal_state_publisher-msg)


;//! \htmlinclude MoveGripperMsg.msg.html

(cl:defclass <MoveGripperMsg> (roslisp-msg-protocol:ros-message)
  ((width
    :reader width
    :initarg :width
    :type cl:float
    :initform 0.0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass MoveGripperMsg (<MoveGripperMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveGripperMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveGripperMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name goal_state_publisher-msg:<MoveGripperMsg> is deprecated: use goal_state_publisher-msg:MoveGripperMsg instead.")))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <MoveGripperMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader goal_state_publisher-msg:width-val is deprecated.  Use goal_state_publisher-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <MoveGripperMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader goal_state_publisher-msg:speed-val is deprecated.  Use goal_state_publisher-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveGripperMsg>) ostream)
  "Serializes a message object of type '<MoveGripperMsg>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveGripperMsg>) istream)
  "Deserializes a message object of type '<MoveGripperMsg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'width) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveGripperMsg>)))
  "Returns string type for a message object of type '<MoveGripperMsg>"
  "goal_state_publisher/MoveGripperMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveGripperMsg)))
  "Returns string type for a message object of type 'MoveGripperMsg"
  "goal_state_publisher/MoveGripperMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveGripperMsg>)))
  "Returns md5sum for a message object of type '<MoveGripperMsg>"
  "d16050a0fe85f1c2cb8347c99678362e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveGripperMsg)))
  "Returns md5sum for a message object of type 'MoveGripperMsg"
  "d16050a0fe85f1c2cb8347c99678362e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveGripperMsg>)))
  "Returns full string definition for message of type '<MoveGripperMsg>"
  (cl:format cl:nil "# A custom message type for sending commands to a Franka gripper~%# Define the message fields~%float64 width~%float64 speed~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveGripperMsg)))
  "Returns full string definition for message of type 'MoveGripperMsg"
  (cl:format cl:nil "# A custom message type for sending commands to a Franka gripper~%# Define the message fields~%float64 width~%float64 speed~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveGripperMsg>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveGripperMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveGripperMsg
    (cl:cons ':width (width msg))
    (cl:cons ':speed (speed msg))
))
