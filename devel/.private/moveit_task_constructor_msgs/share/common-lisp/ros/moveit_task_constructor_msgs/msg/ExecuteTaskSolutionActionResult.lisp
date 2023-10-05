; Auto-generated. Do not edit!


(cl:in-package moveit_task_constructor_msgs-msg)


;//! \htmlinclude ExecuteTaskSolutionActionResult.msg.html

(cl:defclass <ExecuteTaskSolutionActionResult> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (status
    :reader status
    :initarg :status
    :type actionlib_msgs-msg:GoalStatus
    :initform (cl:make-instance 'actionlib_msgs-msg:GoalStatus))
   (result
    :reader result
    :initarg :result
    :type moveit_task_constructor_msgs-msg:ExecuteTaskSolutionResult
    :initform (cl:make-instance 'moveit_task_constructor_msgs-msg:ExecuteTaskSolutionResult)))
)

(cl:defclass ExecuteTaskSolutionActionResult (<ExecuteTaskSolutionActionResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ExecuteTaskSolutionActionResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ExecuteTaskSolutionActionResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name moveit_task_constructor_msgs-msg:<ExecuteTaskSolutionActionResult> is deprecated: use moveit_task_constructor_msgs-msg:ExecuteTaskSolutionActionResult instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ExecuteTaskSolutionActionResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moveit_task_constructor_msgs-msg:header-val is deprecated.  Use moveit_task_constructor_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <ExecuteTaskSolutionActionResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moveit_task_constructor_msgs-msg:status-val is deprecated.  Use moveit_task_constructor_msgs-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ExecuteTaskSolutionActionResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moveit_task_constructor_msgs-msg:result-val is deprecated.  Use moveit_task_constructor_msgs-msg:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ExecuteTaskSolutionActionResult>) ostream)
  "Serializes a message object of type '<ExecuteTaskSolutionActionResult>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'status) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'result) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ExecuteTaskSolutionActionResult>) istream)
  "Deserializes a message object of type '<ExecuteTaskSolutionActionResult>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'status) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'result) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ExecuteTaskSolutionActionResult>)))
  "Returns string type for a message object of type '<ExecuteTaskSolutionActionResult>"
  "moveit_task_constructor_msgs/ExecuteTaskSolutionActionResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ExecuteTaskSolutionActionResult)))
  "Returns string type for a message object of type 'ExecuteTaskSolutionActionResult"
  "moveit_task_constructor_msgs/ExecuteTaskSolutionActionResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ExecuteTaskSolutionActionResult>)))
  "Returns md5sum for a message object of type '<ExecuteTaskSolutionActionResult>"
  "2a052ef9772722c8338e057a61e60639")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ExecuteTaskSolutionActionResult)))
  "Returns md5sum for a message object of type 'ExecuteTaskSolutionActionResult"
  "2a052ef9772722c8338e057a61e60639")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ExecuteTaskSolutionActionResult>)))
  "Returns full string definition for message of type '<ExecuteTaskSolutionActionResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalStatus status~%ExecuteTaskSolutionResult result~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalStatus~%GoalID goal_id~%uint8 status~%uint8 PENDING         = 0   # The goal has yet to be processed by the action server~%uint8 ACTIVE          = 1   # The goal is currently being processed by the action server~%uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing~%                            #   and has since completed its execution (Terminal State)~%uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)~%uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due~%                            #    to some failure (Terminal State)~%uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,~%                            #    because the goal was unattainable or invalid (Terminal State)~%uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing~%                            #    and has not yet completed execution~%uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,~%                            #    but the action server has not yet confirmed that the goal is canceled~%uint8 RECALLED        = 8   # The goal received a cancel request before it started executing~%                            #    and was successfully cancelled (Terminal State)~%uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be~%                            #    sent over the wire by an action server~%~%#Allow for the user to associate a string with GoalStatus for debugging~%string text~%~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: moveit_task_constructor_msgs/ExecuteTaskSolutionResult~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%# result of execution~%moveit_msgs/MoveItErrorCodes error_code~%~%~%================================================================================~%MSG: moveit_msgs/MoveItErrorCodes~%int32 val~%~%# overall behavior~%int32 SUCCESS=1~%int32 FAILURE=99999~%~%int32 PLANNING_FAILED=-1~%int32 INVALID_MOTION_PLAN=-2~%int32 MOTION_PLAN_INVALIDATED_BY_ENVIRONMENT_CHANGE=-3~%int32 CONTROL_FAILED=-4~%int32 UNABLE_TO_AQUIRE_SENSOR_DATA=-5~%int32 TIMED_OUT=-6~%int32 PREEMPTED=-7~%~%# planning & kinematics request errors~%int32 START_STATE_IN_COLLISION=-10~%int32 START_STATE_VIOLATES_PATH_CONSTRAINTS=-11~%int32 START_STATE_INVALID=-26~%~%int32 GOAL_IN_COLLISION=-12~%int32 GOAL_VIOLATES_PATH_CONSTRAINTS=-13~%int32 GOAL_CONSTRAINTS_VIOLATED=-14~%int32 GOAL_STATE_INVALID=-27~%int32 UNRECOGNIZED_GOAL_TYPE=-28~%~%int32 INVALID_GROUP_NAME=-15~%int32 INVALID_GOAL_CONSTRAINTS=-16~%int32 INVALID_ROBOT_STATE=-17~%int32 INVALID_LINK_NAME=-18~%int32 INVALID_OBJECT_NAME=-19~%~%# system errors~%int32 FRAME_TRANSFORM_FAILURE=-21~%int32 COLLISION_CHECKING_UNAVAILABLE=-22~%int32 ROBOT_STATE_STALE=-23~%int32 SENSOR_INFO_STALE=-24~%int32 COMMUNICATION_FAILURE=-25~%int32 CRASH=-29~%int32 ABORT=-30~%~%# kinematics errors~%int32 NO_IK_SOLUTION=-31~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ExecuteTaskSolutionActionResult)))
  "Returns full string definition for message of type 'ExecuteTaskSolutionActionResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalStatus status~%ExecuteTaskSolutionResult result~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalStatus~%GoalID goal_id~%uint8 status~%uint8 PENDING         = 0   # The goal has yet to be processed by the action server~%uint8 ACTIVE          = 1   # The goal is currently being processed by the action server~%uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing~%                            #   and has since completed its execution (Terminal State)~%uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)~%uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due~%                            #    to some failure (Terminal State)~%uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,~%                            #    because the goal was unattainable or invalid (Terminal State)~%uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing~%                            #    and has not yet completed execution~%uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,~%                            #    but the action server has not yet confirmed that the goal is canceled~%uint8 RECALLED        = 8   # The goal received a cancel request before it started executing~%                            #    and was successfully cancelled (Terminal State)~%uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be~%                            #    sent over the wire by an action server~%~%#Allow for the user to associate a string with GoalStatus for debugging~%string text~%~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: moveit_task_constructor_msgs/ExecuteTaskSolutionResult~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%# result of execution~%moveit_msgs/MoveItErrorCodes error_code~%~%~%================================================================================~%MSG: moveit_msgs/MoveItErrorCodes~%int32 val~%~%# overall behavior~%int32 SUCCESS=1~%int32 FAILURE=99999~%~%int32 PLANNING_FAILED=-1~%int32 INVALID_MOTION_PLAN=-2~%int32 MOTION_PLAN_INVALIDATED_BY_ENVIRONMENT_CHANGE=-3~%int32 CONTROL_FAILED=-4~%int32 UNABLE_TO_AQUIRE_SENSOR_DATA=-5~%int32 TIMED_OUT=-6~%int32 PREEMPTED=-7~%~%# planning & kinematics request errors~%int32 START_STATE_IN_COLLISION=-10~%int32 START_STATE_VIOLATES_PATH_CONSTRAINTS=-11~%int32 START_STATE_INVALID=-26~%~%int32 GOAL_IN_COLLISION=-12~%int32 GOAL_VIOLATES_PATH_CONSTRAINTS=-13~%int32 GOAL_CONSTRAINTS_VIOLATED=-14~%int32 GOAL_STATE_INVALID=-27~%int32 UNRECOGNIZED_GOAL_TYPE=-28~%~%int32 INVALID_GROUP_NAME=-15~%int32 INVALID_GOAL_CONSTRAINTS=-16~%int32 INVALID_ROBOT_STATE=-17~%int32 INVALID_LINK_NAME=-18~%int32 INVALID_OBJECT_NAME=-19~%~%# system errors~%int32 FRAME_TRANSFORM_FAILURE=-21~%int32 COLLISION_CHECKING_UNAVAILABLE=-22~%int32 ROBOT_STATE_STALE=-23~%int32 SENSOR_INFO_STALE=-24~%int32 COMMUNICATION_FAILURE=-25~%int32 CRASH=-29~%int32 ABORT=-30~%~%# kinematics errors~%int32 NO_IK_SOLUTION=-31~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ExecuteTaskSolutionActionResult>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'status))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'result))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ExecuteTaskSolutionActionResult>))
  "Converts a ROS message object to a list"
  (cl:list 'ExecuteTaskSolutionActionResult
    (cl:cons ':header (header msg))
    (cl:cons ':status (status msg))
    (cl:cons ':result (result msg))
))
