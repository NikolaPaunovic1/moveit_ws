// Generated by gencpp from file my_services/PickPlaceResult.msg
// DO NOT EDIT!


#ifndef MY_SERVICES_MESSAGE_PICKPLACERESULT_H
#define MY_SERVICES_MESSAGE_PICKPLACERESULT_H


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
struct PickPlaceResult_
{
  typedef PickPlaceResult_<ContainerAllocator> Type;

  PickPlaceResult_()
    : success(false)  {
    }
  PickPlaceResult_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::my_services::PickPlaceResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_services::PickPlaceResult_<ContainerAllocator> const> ConstPtr;

}; // struct PickPlaceResult_

typedef ::my_services::PickPlaceResult_<std::allocator<void> > PickPlaceResult;

typedef boost::shared_ptr< ::my_services::PickPlaceResult > PickPlaceResultPtr;
typedef boost::shared_ptr< ::my_services::PickPlaceResult const> PickPlaceResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_services::PickPlaceResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_services::PickPlaceResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::my_services::PickPlaceResult_<ContainerAllocator1> & lhs, const ::my_services::PickPlaceResult_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::my_services::PickPlaceResult_<ContainerAllocator1> & lhs, const ::my_services::PickPlaceResult_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace my_services

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::my_services::PickPlaceResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_services::PickPlaceResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_services::PickPlaceResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_services::PickPlaceResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_services::PickPlaceResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_services::PickPlaceResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_services::PickPlaceResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::my_services::PickPlaceResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::my_services::PickPlaceResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_services/PickPlaceResult";
  }

  static const char* value(const ::my_services::PickPlaceResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_services::PickPlaceResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#result definition\n"
"bool success\n"
;
  }

  static const char* value(const ::my_services::PickPlaceResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_services::PickPlaceResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PickPlaceResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_services::PickPlaceResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_services::PickPlaceResult_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_SERVICES_MESSAGE_PICKPLACERESULT_H