// Generated by gencpp from file my_services/PoseFinderServiceRequest.msg
// DO NOT EDIT!


#ifndef MY_SERVICES_MESSAGE_POSEFINDERSERVICEREQUEST_H
#define MY_SERVICES_MESSAGE_POSEFINDERSERVICEREQUEST_H


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
struct PoseFinderServiceRequest_
{
  typedef PoseFinderServiceRequest_<ContainerAllocator> Type;

  PoseFinderServiceRequest_()
    : location()
    , id(0)  {
    }
  PoseFinderServiceRequest_(const ContainerAllocator& _alloc)
    : location(_alloc)
    , id(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _location_type;
  _location_type location;

   typedef uint8_t _id_type;
  _id_type id;





  typedef boost::shared_ptr< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct PoseFinderServiceRequest_

typedef ::my_services::PoseFinderServiceRequest_<std::allocator<void> > PoseFinderServiceRequest;

typedef boost::shared_ptr< ::my_services::PoseFinderServiceRequest > PoseFinderServiceRequestPtr;
typedef boost::shared_ptr< ::my_services::PoseFinderServiceRequest const> PoseFinderServiceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_services::PoseFinderServiceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::my_services::PoseFinderServiceRequest_<ContainerAllocator1> & lhs, const ::my_services::PoseFinderServiceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.location == rhs.location &&
    lhs.id == rhs.id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::my_services::PoseFinderServiceRequest_<ContainerAllocator1> & lhs, const ::my_services::PoseFinderServiceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace my_services

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "10380e0edbd00c1c67120e216d39ae1e";
  }

  static const char* value(const ::my_services::PoseFinderServiceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x10380e0edbd00c1cULL;
  static const uint64_t static_value2 = 0x67120e216d39ae1eULL;
};

template<class ContainerAllocator>
struct DataType< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_services/PoseFinderServiceRequest";
  }

  static const char* value(const ::my_services::PoseFinderServiceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string location\n"
"uint8 id\n"
;
  }

  static const char* value(const ::my_services::PoseFinderServiceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.location);
      stream.next(m.id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PoseFinderServiceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_services::PoseFinderServiceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_services::PoseFinderServiceRequest_<ContainerAllocator>& v)
  {
    s << indent << "location: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.location);
    s << indent << "id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_SERVICES_MESSAGE_POSEFINDERSERVICEREQUEST_H
