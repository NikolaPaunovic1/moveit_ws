// Auto-generated. Do not edit!

// (in-package my_services.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class ObjectPositionServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.shape_name = null;
    }
    else {
      if (initObj.hasOwnProperty('shape_name')) {
        this.shape_name = initObj.shape_name
      }
      else {
        this.shape_name = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObjectPositionServiceRequest
    // Serialize message field [shape_name]
    bufferOffset = _serializer.string(obj.shape_name, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObjectPositionServiceRequest
    let len;
    let data = new ObjectPositionServiceRequest(null);
    // Deserialize message field [shape_name]
    data.shape_name = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.shape_name);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'my_services/ObjectPositionServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c9b199430e4a77523827a4eb6836d449';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string shape_name
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObjectPositionServiceRequest(null);
    if (msg.shape_name !== undefined) {
      resolved.shape_name = msg.shape_name;
    }
    else {
      resolved.shape_name = ''
    }

    return resolved;
    }
};

class ObjectPositionServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.object_pose = null;
    }
    else {
      if (initObj.hasOwnProperty('object_pose')) {
        this.object_pose = initObj.object_pose
      }
      else {
        this.object_pose = new geometry_msgs.msg.Pose();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObjectPositionServiceResponse
    // Serialize message field [object_pose]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.object_pose, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObjectPositionServiceResponse
    let len;
    let data = new ObjectPositionServiceResponse(null);
    // Deserialize message field [object_pose]
    data.object_pose = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 56;
  }

  static datatype() {
    // Returns string type for a service object
    return 'my_services/ObjectPositionServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4f370b349a20e2e0029b6c926ba1b874';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Pose object_pose
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObjectPositionServiceResponse(null);
    if (msg.object_pose !== undefined) {
      resolved.object_pose = geometry_msgs.msg.Pose.Resolve(msg.object_pose)
    }
    else {
      resolved.object_pose = new geometry_msgs.msg.Pose()
    }

    return resolved;
    }
};

module.exports = {
  Request: ObjectPositionServiceRequest,
  Response: ObjectPositionServiceResponse,
  md5sum() { return '6d1b74b2e09de95ba7cb8ac42e760730'; },
  datatype() { return 'my_services/ObjectPositionService'; }
};
