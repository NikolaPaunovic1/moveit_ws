;; Auto-generated. Do not edit!


(when (boundp 'moveit_task_constructor_msgs::StageStatistics)
  (if (not (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS"))
    (make-package "MOVEIT_TASK_CONSTRUCTOR_MSGS"))
  (shadow 'StageStatistics (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS")))
(unless (find-package "MOVEIT_TASK_CONSTRUCTOR_MSGS::STAGESTATISTICS")
  (make-package "MOVEIT_TASK_CONSTRUCTOR_MSGS::STAGESTATISTICS"))

(in-package "ROS")
;;//! \htmlinclude StageStatistics.msg.html


(defclass moveit_task_constructor_msgs::StageStatistics
  :super ros::object
  :slots (_id _solved _failed _num_failed _total_compute_time ))

(defmethod moveit_task_constructor_msgs::StageStatistics
  (:init
   (&key
    ((:id __id) 0)
    ((:solved __solved) (make-array 0 :initial-element 0 :element-type :integer))
    ((:failed __failed) (make-array 0 :initial-element 0 :element-type :integer))
    ((:num_failed __num_failed) 0)
    ((:total_compute_time __total_compute_time) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _solved __solved)
   (setq _failed __failed)
   (setq _num_failed (round __num_failed))
   (setq _total_compute_time (float __total_compute_time))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:solved
   (&optional __solved)
   (if __solved (setq _solved __solved)) _solved)
  (:failed
   (&optional __failed)
   (if __failed (setq _failed __failed)) _failed)
  (:num_failed
   (&optional __num_failed)
   (if __num_failed (setq _num_failed __num_failed)) _num_failed)
  (:total_compute_time
   (&optional __total_compute_time)
   (if __total_compute_time (setq _total_compute_time __total_compute_time)) _total_compute_time)
  (:serialization-length
   ()
   (+
    ;; uint32 _id
    4
    ;; uint32[] _solved
    (* 4    (length _solved)) 4
    ;; uint32[] _failed
    (* 4    (length _failed)) 4
    ;; uint32 _num_failed
    4
    ;; float64 _total_compute_time
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _id
       (write-long _id s)
     ;; uint32[] _solved
     (write-long (length _solved) s)
     (dotimes (i (length _solved))
       (write-long (elt _solved i) s)
       )
     ;; uint32[] _failed
     (write-long (length _failed) s)
     (dotimes (i (length _failed))
       (write-long (elt _failed i) s)
       )
     ;; uint32 _num_failed
       (write-long _num_failed s)
     ;; float64 _total_compute_time
       (sys::poke _total_compute_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32[] _solved
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _solved (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _solved i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32[] _failed
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _failed (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _failed i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32 _num_failed
     (setq _num_failed (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _total_compute_time
     (setq _total_compute_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get moveit_task_constructor_msgs::StageStatistics :md5sum-) "a3065cf7e54eaf169fb84102f63f1ac2")
(setf (get moveit_task_constructor_msgs::StageStatistics :datatype-) "moveit_task_constructor_msgs/StageStatistics")
(setf (get moveit_task_constructor_msgs::StageStatistics :definition-)
      "# dynamically changing information for a stage

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



(provide :moveit_task_constructor_msgs/StageStatistics "a3065cf7e54eaf169fb84102f63f1ac2")


