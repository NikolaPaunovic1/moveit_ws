; Auto-generated. Do not edit!


(cl:in-package moveit_task_constructor_msgs-msg)


;//! \htmlinclude TaskDescription.msg.html

(cl:defclass <TaskDescription> (roslisp-msg-protocol:ros-message)
  ((task_id
    :reader task_id
    :initarg :task_id
    :type cl:string
    :initform "")
   (stages
    :reader stages
    :initarg :stages
    :type (cl:vector moveit_task_constructor_msgs-msg:StageDescription)
   :initform (cl:make-array 0 :element-type 'moveit_task_constructor_msgs-msg:StageDescription :initial-element (cl:make-instance 'moveit_task_constructor_msgs-msg:StageDescription))))
)

(cl:defclass TaskDescription (<TaskDescription>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TaskDescription>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TaskDescription)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name moveit_task_constructor_msgs-msg:<TaskDescription> is deprecated: use moveit_task_constructor_msgs-msg:TaskDescription instead.")))

(cl:ensure-generic-function 'task_id-val :lambda-list '(m))
(cl:defmethod task_id-val ((m <TaskDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moveit_task_constructor_msgs-msg:task_id-val is deprecated.  Use moveit_task_constructor_msgs-msg:task_id instead.")
  (task_id m))

(cl:ensure-generic-function 'stages-val :lambda-list '(m))
(cl:defmethod stages-val ((m <TaskDescription>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moveit_task_constructor_msgs-msg:stages-val is deprecated.  Use moveit_task_constructor_msgs-msg:stages instead.")
  (stages m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TaskDescription>) ostream)
  "Serializes a message object of type '<TaskDescription>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'task_id))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'task_id))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'stages))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'stages))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TaskDescription>) istream)
  "Deserializes a message object of type '<TaskDescription>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'task_id) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'task_id) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'stages) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'stages)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'moveit_task_constructor_msgs-msg:StageDescription))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TaskDescription>)))
  "Returns string type for a message object of type '<TaskDescription>"
  "moveit_task_constructor_msgs/TaskDescription")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TaskDescription)))
  "Returns string type for a message object of type 'TaskDescription"
  "moveit_task_constructor_msgs/TaskDescription")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TaskDescription>)))
  "Returns md5sum for a message object of type '<TaskDescription>"
  "54c0104c9822086952fd493bd0d4655d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TaskDescription)))
  "Returns md5sum for a message object of type 'TaskDescription"
  "54c0104c9822086952fd493bd0d4655d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TaskDescription>)))
  "Returns full string definition for message of type '<TaskDescription>"
  (cl:format cl:nil "# unique id of this task~%string task_id~%~%# list of all stages, including the task stage itself~%StageDescription[] stages~%~%================================================================================~%MSG: moveit_task_constructor_msgs/StageDescription~%# static description of a stage~%~%# unique id within task~%uint32 id~%~%# parent id, parent_id == id means root~%uint32 parent_id~%~%# name of this stage~%string name~%~%# flags: interface, ...~%uint32 flags~%~%# properties~%Property[] properties~%~%================================================================================~%MSG: moveit_task_constructor_msgs/Property~%string name~%string description~%string type~%string value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TaskDescription)))
  "Returns full string definition for message of type 'TaskDescription"
  (cl:format cl:nil "# unique id of this task~%string task_id~%~%# list of all stages, including the task stage itself~%StageDescription[] stages~%~%================================================================================~%MSG: moveit_task_constructor_msgs/StageDescription~%# static description of a stage~%~%# unique id within task~%uint32 id~%~%# parent id, parent_id == id means root~%uint32 parent_id~%~%# name of this stage~%string name~%~%# flags: interface, ...~%uint32 flags~%~%# properties~%Property[] properties~%~%================================================================================~%MSG: moveit_task_constructor_msgs/Property~%string name~%string description~%string type~%string value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TaskDescription>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'task_id))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'stages) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TaskDescription>))
  "Converts a ROS message object to a list"
  (cl:list 'TaskDescription
    (cl:cons ':task_id (task_id msg))
    (cl:cons ':stages (stages msg))
))
