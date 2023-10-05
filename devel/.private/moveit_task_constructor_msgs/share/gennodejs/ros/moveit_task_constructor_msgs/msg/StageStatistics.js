// Auto-generated. Do not edit!

// (in-package moveit_task_constructor_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class StageStatistics {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
      this.solved = null;
      this.failed = null;
      this.num_failed = null;
      this.total_compute_time = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('solved')) {
        this.solved = initObj.solved
      }
      else {
        this.solved = [];
      }
      if (initObj.hasOwnProperty('failed')) {
        this.failed = initObj.failed
      }
      else {
        this.failed = [];
      }
      if (initObj.hasOwnProperty('num_failed')) {
        this.num_failed = initObj.num_failed
      }
      else {
        this.num_failed = 0;
      }
      if (initObj.hasOwnProperty('total_compute_time')) {
        this.total_compute_time = initObj.total_compute_time
      }
      else {
        this.total_compute_time = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type StageStatistics
    // Serialize message field [id]
    bufferOffset = _serializer.uint32(obj.id, buffer, bufferOffset);
    // Serialize message field [solved]
    bufferOffset = _arraySerializer.uint32(obj.solved, buffer, bufferOffset, null);
    // Serialize message field [failed]
    bufferOffset = _arraySerializer.uint32(obj.failed, buffer, bufferOffset, null);
    // Serialize message field [num_failed]
    bufferOffset = _serializer.uint32(obj.num_failed, buffer, bufferOffset);
    // Serialize message field [total_compute_time]
    bufferOffset = _serializer.float64(obj.total_compute_time, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type StageStatistics
    let len;
    let data = new StageStatistics(null);
    // Deserialize message field [id]
    data.id = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [solved]
    data.solved = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [failed]
    data.failed = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [num_failed]
    data.num_failed = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [total_compute_time]
    data.total_compute_time = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.solved.length;
    length += 4 * object.failed.length;
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'moveit_task_constructor_msgs/StageStatistics';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a3065cf7e54eaf169fb84102f63f1ac2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new StageStatistics(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.solved !== undefined) {
      resolved.solved = msg.solved;
    }
    else {
      resolved.solved = []
    }

    if (msg.failed !== undefined) {
      resolved.failed = msg.failed;
    }
    else {
      resolved.failed = []
    }

    if (msg.num_failed !== undefined) {
      resolved.num_failed = msg.num_failed;
    }
    else {
      resolved.num_failed = 0
    }

    if (msg.total_compute_time !== undefined) {
      resolved.total_compute_time = msg.total_compute_time;
    }
    else {
      resolved.total_compute_time = 0.0
    }

    return resolved;
    }
};

module.exports = StageStatistics;
