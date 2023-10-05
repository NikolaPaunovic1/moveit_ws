; Auto-generated. Do not edit!


(cl:in-package goal_state_publisher-msg)


;//! \htmlinclude StopGripperMsg.msg.html

(cl:defclass <StopGripperMsg> (roslisp-msg-protocol:ros-message)
  ((isStop
    :reader isStop
    :initarg :isStop
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass StopGripperMsg (<StopGripperMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StopGripperMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StopGripperMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name goal_state_publisher-msg:<StopGripperMsg> is deprecated: use goal_state_publisher-msg:StopGripperMsg instead.")))

(cl:ensure-generic-function 'isStop-val :lambda-list '(m))
(cl:defmethod isStop-val ((m <StopGripperMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader goal_state_publisher-msg:isStop-val is deprecated.  Use goal_state_publisher-msg:isStop instead.")
  (isStop m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StopGripperMsg>) ostream)
  "Serializes a message object of type '<StopGripperMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isStop) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StopGripperMsg>) istream)
  "Deserializes a message object of type '<StopGripperMsg>"
    (cl:setf (cl:slot-value msg 'isStop) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StopGripperMsg>)))
  "Returns string type for a message object of type '<StopGripperMsg>"
  "goal_state_publisher/StopGripperMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StopGripperMsg)))
  "Returns string type for a message object of type 'StopGripperMsg"
  "goal_state_publisher/StopGripperMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StopGripperMsg>)))
  "Returns md5sum for a message object of type '<StopGripperMsg>"
  "4e622c3bf7f741ad63c7902f5596d407")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StopGripperMsg)))
  "Returns md5sum for a message object of type 'StopGripperMsg"
  "4e622c3bf7f741ad63c7902f5596d407")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StopGripperMsg>)))
  "Returns full string definition for message of type '<StopGripperMsg>"
  (cl:format cl:nil "# A custom message type for sending commands to a Franka gripper~%# Define the message fields~%bool isStop~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StopGripperMsg)))
  "Returns full string definition for message of type 'StopGripperMsg"
  (cl:format cl:nil "# A custom message type for sending commands to a Franka gripper~%# Define the message fields~%bool isStop~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StopGripperMsg>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StopGripperMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'StopGripperMsg
    (cl:cons ':isStop (isStop msg))
))
