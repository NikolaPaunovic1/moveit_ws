; Auto-generated. Do not edit!


(cl:in-package my_services-msg)


;//! \htmlinclude PickPlaceResult.msg.html

(cl:defclass <PickPlaceResult> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass PickPlaceResult (<PickPlaceResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PickPlaceResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PickPlaceResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name my_services-msg:<PickPlaceResult> is deprecated: use my_services-msg:PickPlaceResult instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <PickPlaceResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader my_services-msg:success-val is deprecated.  Use my_services-msg:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PickPlaceResult>) ostream)
  "Serializes a message object of type '<PickPlaceResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PickPlaceResult>) istream)
  "Deserializes a message object of type '<PickPlaceResult>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PickPlaceResult>)))
  "Returns string type for a message object of type '<PickPlaceResult>"
  "my_services/PickPlaceResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PickPlaceResult)))
  "Returns string type for a message object of type 'PickPlaceResult"
  "my_services/PickPlaceResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PickPlaceResult>)))
  "Returns md5sum for a message object of type '<PickPlaceResult>"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PickPlaceResult)))
  "Returns md5sum for a message object of type 'PickPlaceResult"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PickPlaceResult>)))
  "Returns full string definition for message of type '<PickPlaceResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PickPlaceResult)))
  "Returns full string definition for message of type 'PickPlaceResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PickPlaceResult>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PickPlaceResult>))
  "Converts a ROS message object to a list"
  (cl:list 'PickPlaceResult
    (cl:cons ':success (success msg))
))
