// Generated by gencpp from file my_services/PickPlace2Feedback.msg
// DO NOT EDIT!


#ifndef MY_SERVICES_MESSAGE_PICKPLACE2FEEDBACK_H
#define MY_SERVICES_MESSAGE_PICKPLACE2FEEDBACK_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace my_services
{
template <class ContainerAllocator>
struct PickPlace2Feedback_
{
  typedef PickPlace2Feedback_<ContainerAllocator> Type;

  PickPlace2Feedback_()
    : info()  {
    }
  PickPlace2Feedback_(const ContainerAllocator& _alloc)
    : info(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _info_type;
  _info_type info;





  typedef boost::shared_ptr< ::my_services::PickPlace2Feedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_services::PickPlace2Feedback_<ContainerAllocator> const> ConstPtr;

}; // struct PickPlace2Feedback_

typedef ::my_services::PickPlace2Feedback_<std::allocator<void> > PickPlace2Feedback;

typedef boost::shared_ptr< ::my_services::PickPlace2Feedback > PickPlace2FeedbackPtr;
typedef boost::shared_ptr< ::my_services::PickPlace2Feedback const> PickPlace2FeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_services::PickPlace2Feedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_services::PickPlace2Feedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::my_services::PickPlace2Feedback_<ContainerAllocator1> & lhs, const ::my_services::PickPlace2Feedback_<ContainerAllocator2> & rhs)
{
  return lhs.info == rhs.info;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::my_services::PickPlace2Feedback_<ContainerAllocator1> & lhs, const ::my_services::PickPlace2Feedback_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace my_services

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_services::PickPlace2Feedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_services::PickPlace2Feedback_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_services::PickPlace2Feedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c10fc26d5cca9a4b9114f5fc5dea9570";
  }

  static const char* value(const ::my_services::PickPlace2Feedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc10fc26d5cca9a4bULL;
  static const uint64_t static_value2 = 0x9114f5fc5dea9570ULL;
};

template<class ContainerAllocator>
struct DataType< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_services/PickPlace2Feedback";
  }

  static const char* value(const ::my_services::PickPlace2Feedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#feedback\n"
"string info\n"
"\n"
;
  }

  static const char* value(const ::my_services::PickPlace2Feedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.info);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PickPlace2Feedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_services::PickPlace2Feedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_services::PickPlace2Feedback_<ContainerAllocator>& v)
  {
    s << indent << "info: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.info);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_SERVICES_MESSAGE_PICKPLACE2FEEDBACK_H
