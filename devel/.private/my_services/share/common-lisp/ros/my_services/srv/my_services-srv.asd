
(cl:in-package :asdf)

(defsystem "my_services-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "ObjectPositionService" :depends-on ("_package_ObjectPositionService"))
    (:file "_package_ObjectPositionService" :depends-on ("_package"))
    (:file "PoseFinderService" :depends-on ("_package_PoseFinderService"))
    (:file "_package_PoseFinderService" :depends-on ("_package"))
  ))