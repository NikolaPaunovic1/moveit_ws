// Generated by gencpp from file moveit_task_constructor_msgs/TaskStatistics.msg
// DO NOT EDIT!


#ifndef MOVEIT_TASK_CONSTRUCTOR_MSGS_MESSAGE_TASKSTATISTICS_H
#define MOVEIT_TASK_CONSTRUCTOR_MSGS_MESSAGE_TASKSTATISTICS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <moveit_task_constructor_msgs/StageStatistics.h>

namespace moveit_task_constructor_msgs
{
template <class ContainerAllocator>
struct TaskStatistics_
{
  typedef TaskStatistics_<ContainerAllocator> Type;

  TaskStatistics_()
    : task_id()
    , stages()  {
    }
  TaskStatistics_(const ContainerAllocator& _alloc)
    : task_id(_alloc)
    , stages(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _task_id_type;
  _task_id_type task_id;

   typedef std::vector< ::moveit_task_constructor_msgs::StageStatistics_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::moveit_task_constructor_msgs::StageStatistics_<ContainerAllocator> >> _stages_type;
  _stages_type stages;





  typedef boost::shared_ptr< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> const> ConstPtr;

}; // struct TaskStatistics_

typedef ::moveit_task_constructor_msgs::TaskStatistics_<std::allocator<void> > TaskStatistics;

typedef boost::shared_ptr< ::moveit_task_constructor_msgs::TaskStatistics > TaskStatisticsPtr;
typedef boost::shared_ptr< ::moveit_task_constructor_msgs::TaskStatistics const> TaskStatisticsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator1> & lhs, const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator2> & rhs)
{
  return lhs.task_id == rhs.task_id &&
    lhs.stages == rhs.stages;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator1> & lhs, const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace moveit_task_constructor_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f18c50166b7446a7ec6179ed1d6aa3d1";
  }

  static const char* value(const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf18c50166b7446a7ULL;
  static const uint64_t static_value2 = 0xec6179ed1d6aa3d1ULL;
};

template<class ContainerAllocator>
struct DataType< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
{
  static const char* value()
  {
    return "moveit_task_constructor_msgs/TaskStatistics";
  }

  static const char* value(const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# unique id of generating task\n"
"string task_id\n"
"\n"
"# list of all stages, including the task stage itself\n"
"StageStatistics[] stages\n"
"\n"
"================================================================================\n"
"MSG: moveit_task_constructor_msgs/StageStatistics\n"
"# dynamically changing information for a stage\n"
"\n"
"# unique id within task\n"
"uint32 id\n"
"\n"
"# successful solution IDs of this stage, sorted by increasing cost\n"
"uint32[] solved\n"
"\n"
"# (optional) failed solution IDs of this stage\n"
"uint32[] failed\n"
"# number of failed solutions (if failed is empty)\n"
"uint32   num_failed\n"
"# total computation time in seconds\n"
"float64 total_compute_time\n"
;
  }

  static const char* value(const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.task_id);
      stream.next(m.stages);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TaskStatistics_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::moveit_task_constructor_msgs::TaskStatistics_<ContainerAllocator>& v)
  {
    s << indent << "task_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.task_id);
    s << indent << "stages[]" << std::endl;
    for (size_t i = 0; i < v.stages.size(); ++i)
    {
      s << indent << "  stages[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::moveit_task_constructor_msgs::StageStatistics_<ContainerAllocator> >::stream(s, indent + "    ", v.stages[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOVEIT_TASK_CONSTRUCTOR_MSGS_MESSAGE_TASKSTATISTICS_H
