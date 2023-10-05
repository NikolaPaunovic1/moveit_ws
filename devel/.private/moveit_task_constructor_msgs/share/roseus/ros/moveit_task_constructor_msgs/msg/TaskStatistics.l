;; Auto-generated. Do not edit!


(when (boundp 'moveit_task_constructor_msgs::TaskStatistics)
  (if (not (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS"))
    (make-package "MOVEIT_TASK_CONSTRUCTOR_MSGS"))
  (shadow 'TaskStatistics (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS")))
(unless (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS::TASKSTATISTICS")
  (make-package "MOVEIT_TASK_CONSTRUCTOR_MSGS::TASKSTATISTICS"))

(in-package "ROS")
;;//! \htmlinclude TaskStatistics.msg.html


(defclass moveit_task_constructor_msgs::TaskStatistics
  :super ros::object
  :slots (_task_id _stages ))

(defmethod moveit_task_constructor_msgs::TaskStatistics
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
    ;; moveit_task_constructor_msgs/StageStatistics[] _stages
    (apply #'+ (send-all _stages :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _task_id
       (write-long (length _task_id) s) (princ _task_id s)
     ;; moveit_task_constructor_msgs/StageStatistics[] _stages
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
   ;; moveit_task_constructor_msgs/StageStatistics[] _stages
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _stages (let (r) (dotimes (i n) (push (instance moveit_task_constructor_msgs::StageStatistics :init) r)) r))
     (dolist (elem- _stages)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get moveit_task_constructor_msgs::TaskStatistics :md5sum-) "f18c50166b7446a7ec6179ed1d6aa3d1")
(setf (get moveit_task_constructor_msgs::TaskStatistics :datatype-) "moveit_task_constructor_msgs/TaskStatistics")
(setf (get moveit_task_constructor_msgs::TaskStatistics :definition-)
      "# unique id of generating task
string task_id

# list of all stages, including the task stage itself
StageStatistics[] stages

================================================================================
MSG: moveit_task_constructor_msgs/StageStatistics
# dynamically changing information for a stage

# unique id within task
uint32 id

# successful solution IDs of this stage, sorted by increasing cost
uint32[] solved

# (optional) failed solution IDs of this stage
uint32[] failed
# number of failed solutions (if failed is empty)
uint32   num_failed
# total computation time in seconds
float64 total_compute_time

")



(provide :moveit_task_constructor_msgs/TaskStatistics "f18c50166b7446a7ec6179ed1d6aa3d1")


