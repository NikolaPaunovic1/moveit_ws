// Auto-generated. Do not edit!

// (in-package moveit_task_constructor_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let StageDescription = require('./StageDescription.js');

//-----------------------------------------------------------

class TaskDescription {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.task_id = null;
      this.stages = null;
    }
    else {
      if (initObj.hasOwnProperty('task_id')) {
        this.task_id = initObj.task_id
      }
      else {
        this.task_id = '';
      }
      if (initObj.hasOwnProperty('stages')) {
        this.stages = initObj.stages
      }
      else {
        this.stages = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TaskDescription
    // Serialize message field [task_id]
    bufferOffset = _serializer.string(obj.task_id, buffer, bufferOffset);
    // Serialize message field [stages]
    // Serialize the length for message field [stages]
    bufferOffset = _serializer.uint32(obj.stages.length, buffer, bufferOffset);
    obj.stages.forEach((val) => {
      bufferOffset = StageDescription.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TaskDescription
    let len;
    let data = new TaskDescription(null);
    // Deserialize message field [task_id]
    data.task_id = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [stages]
    // Deserialize array length for message field [stages]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.stages = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.stages[i] = StageDescription.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.task_id);
    object.stages.forEach((val) => {
      length += StageDescription.getMessageSize(val);
    });
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'moveit_task_constructor_msgs/TaskDescription';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '54c0104c9822086952fd493bd0d4655d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # unique id of this task
    string task_id
    
    # list of all stages, including the task stage itself
    StageDescription[] stages
    
    ================================================================================
    MSG: moveit_task_constructor_msgs/StageDescription
    # static description of a stage
    
    # unique id within task
    uint32 id
    
    # parent id, parent_id == id means root
    uint32 parent_id
    
    # name of this stage
    string name
    
    # flags: interface, ...
    uint32 flags
    
    # properties
    Property[] properties
    
    ================================================================================
    MSG: moveit_task_constructor_msgs/Property
    string name
    string description
    string type
    string value
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TaskDescription(null);
    if (msg.task_id !== undefined) {
      resolved.task_id = msg.task_id;
    }
    else {
      resolved.task_id = ''
    }

    if (msg.stages !== undefined) {
      resolved.stages = new Array(msg.stages.length);
      for (let i = 0; i < resolved.stages.length; ++i) {
        resolved.stages[i] = StageDescription.Resolve(msg.stages[i]);
      }
    }
    else {
      resolved.stages = []
    }

    return resolved;
    }
};

module.exports = TaskDescription;
