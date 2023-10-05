// Generated by gencpp from file unity_robotics_demo_msgs/PositionServiceRequest.msg
// DO NOT EDIT!


#ifndef UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_POSITIONSERVICEREQUEST_H
#define UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_POSITIONSERVICEREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <unity_robotics_demo_msgs/PosRot.h>

namespace unity_robotics_demo_msgs
{
template <class ContainerAllocator>
struct PositionServiceRequest_
{
  typedef PositionServiceRequest_<ContainerAllocator> Type;

  PositionServiceRequest_()
    : input()  {
    }
  PositionServiceRequest_(const ContainerAllocator& _alloc)
    : input(_alloc)  {
  (void)_alloc;
    }



   typedef  ::unity_robotics_demo_msgs::PosRot_<ContainerAllocator>  _input_type;
  _input_type input;





  typedef boost::shared_ptr< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct PositionServiceRequest_

typedef ::unity_robotics_demo_msgs::PositionServiceRequest_<std::allocator<void> > PositionServiceRequest;

typedef boost::shared_ptr< ::unity_robotics_demo_msgs::PositionServiceRequest > PositionServiceRequestPtr;
typedef boost::shared_ptr< ::unity_robotics_demo_msgs::PositionServiceRequest const> PositionServiceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator1> & lhs, const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.input == rhs.input;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator1> & lhs, const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace unity_robotics_demo_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f8e4a2d3805052790871d9acbcc92af5";
  }

  static const char* value(const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf8e4a2d380505279ULL;
  static const uint64_t static_value2 = 0x0871d9acbcc92af5ULL;
};

template<class ContainerAllocator>
struct DataType< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "unity_robotics_demo_msgs/PositionServiceRequest";
  }

  static const char* value(const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "PosRot input\n"
"\n"
"================================================================================\n"
"MSG: unity_robotics_demo_msgs/PosRot\n"
"float32 pos_x\n"
"float32 pos_y\n"
"float32 pos_z\n"
"float32 rot_x\n"
"float32 rot_y\n"
"float32 rot_z\n"
"float32 rot_w\n"
;
  }

  static const char* value(const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.input);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PositionServiceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::unity_robotics_demo_msgs::PositionServiceRequest_<ContainerAllocator>& v)
  {
    s << indent << "input: ";
    s << std::endl;
    Printer< ::unity_robotics_demo_msgs::PosRot_<ContainerAllocator> >::stream(s, indent + "  ", v.input);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UNITY_ROBOTICS_DEMO_MSGS_MESSAGE_POSITIONSERVICEREQUEST_H
