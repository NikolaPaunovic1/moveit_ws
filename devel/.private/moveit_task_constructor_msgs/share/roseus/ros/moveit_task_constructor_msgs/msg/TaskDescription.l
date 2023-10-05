;; Auto-generated. Do not edit!


(when (boundp 'moveit_task_constructor_msgs::TaskDescription)
  (if (not (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS"))
    (make-package "MOVEIT_TASK_CONSTRUCTOR_MSGS"))
  (shadow 'TaskDescription (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS")))
(unless (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS::TASKDESCRIPTION")
  (make-package "MOVEIT_TASK_CONSTRUCTOR_MSGS::TASKDESCRIPTION"))

(in-package "ROS")
;;//! \htmlinclude TaskDescription.msg.html


(defclass moveit_task_constructor_msgs::TaskDescription
  :super ros::object
  :slots (_task_id _stages ))

(defmethod moveit_task_constructor_msgs::TaskDescription
  (:init
   (&key
    ((:task_id __task_id) "")
    ((:stages __stages) ())
    )
   (send-super :init)
   (setq _task_id (string __task_id))
   (setq _stages __stages)
   self)
  (:task_id
   (&optional __task_id)
   (if __task_id (setq _task_id __task_id)) _task_id)
  (:stages
   (&rest __stages)
   (if (keywordp (car __stages))
       (send* _stages __stages)
     (progn
       (if __stages (setq _stages (car __stages)))
       _stages)))
  (:serialization-length
   ()
   (+
    ;; string _task_id
    4 (length _task_id)
    ;; moveit_task_constructor_msgs/StageDescription[] _stages
    (apply #'+ (send-all _stages :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _task_id
       (write-long (length _task_id) s) (princ _task_id s)
     ;; moveit_task_constructor_msgs/StageDescription[] _stages
     (write-long (length _stages) s)
     (dolist (elem _stages)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _task_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _task_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; moveit_task_constructor_msgs/StageDescription[] _stages
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _stages (let (r) (dotimes (i n) (push (instance moveit_task_constructor_msgs::StageDescription :init) r)) r))
     (dolist (elem- _stages)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get moveit_task_constructor_msgs::TaskDescription :md5sum-) "54c0104c9822086952fd493bd0d4655d")
(setf (get moveit_task_constructor_msgs::TaskDescription :datatype-) "moveit_task_constructor_msgs/TaskDescription")
(setf (get moveit_task_constructor_msgs::TaskDescription :definition-)
      "# unique id of this task
string task_id

# list of all stages, including the task stage itself
StageDescription[] stages

================================================================================
MSG: moveit_task_constructor_msgs/StageDescription
# static description of a stage

# unique id within task
uint32 id

# parent id, parent_id == id means root
uint32 parent_id

# name of this stage
string name

# flags: interface, ...
uint32 flags

# properties
Property[] properties

================================================================================
MSG: moveit_task_constructor_msgs/Property
string name
string description
string type
string value

")



(provide :moveit_task_constructor_msgs/TaskDescription "54c0104c9822086952fd493bd0d4655d")


