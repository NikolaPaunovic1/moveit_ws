
(cl:in-package :asdf)

(defsystem "goal_state_publisher-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "GraspMsg" :depends-on ("_package_GraspMsg"))
    (:file "_package_GraspMsg" :depends-on ("_package"))
    (:file "MoveGripperMsg" :depends-on ("_package_MoveGripperMsg"))
    (:file "_package_MoveGripperMsg" :depends-on ("_package"))
    (:file "StopGripperMsg" :depends-on ("_package_StopGripperMsg"))
    (:file "_package_StopGripperMsg" :depends-on ("_package"))
  ))