/**
 * @fileoverview
 * @enhanceable
 * @public
 */
// GENERATED CODE -- DO NOT EDIT!

var jspb = require('google-protobuf');
var goog = jspb;
var global = Function('return this')();

var NullPmd_pb = require('./NullPmd_pb.js');
goog.exportSymbol('proto.MatchPmd.tagGameMatch_s2c', null, global);
goog.exportSymbol('proto.MatchPmd.tagMatchRewardInfo', null, global);

/**
 * Generated by JsPbCodeGenerator.
 * @param {Array=} opt_data Optional initial data array, typically from a
 * server response, or constructed directly in Javascript. The array is used
 * in place and becomes part of the constructed object. It is not cloned.
 * If no data is provided, the constructed object will be empty, but still
 * valid.
 * @extends {jspb.Message}
 * @constructor
 */
proto.MatchPmd.tagMatchRewardInfo = function(opt_data) {
  jspb.Message.initialize(this, opt_data, 0, -1, null, null);
};
goog.inherits(proto.MatchPmd.tagMatchRewardInfo, jspb.Message);
if (goog.DEBUG && !COMPILED) {
  proto.MatchPmd.tagMatchRewardInfo.displayName = 'proto.MatchPmd.tagMatchRewardInfo';
}


if (jspb.Message.GENERATE_TO_OBJECT) {
/**
 * Creates an object representation of this proto suitable for use in Soy templates.
 * Field names that are reserved in JavaScript and will be renamed to pb_name.
 * To access a reserved field use, foo.pb_<name>, eg, foo.pb_default.
 * For the list of reserved names please see:
 *     com.google.apps.jspb.JsClassTemplate.JS_RESERVED_WORDS.
 * @param {boolean=} opt_includeInstance Whether to include the JSPB instance
 *     for transitional soy proto support: http://goto/soy-param-migration
 * @return {!Object}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.toObject = function(opt_includeInstance) {
  return proto.MatchPmd.tagMatchRewardInfo.toObject(opt_includeInstance, this);
};


/**
 * Static version of the {@see toObject} method.
 * @param {boolean|undefined} includeInstance Whether to include the JSPB
 *     instance for transitional soy proto support:
 *     http://goto/soy-param-migration
 * @param {!proto.MatchPmd.tagMatchRewardInfo} msg The msg instance to transform.
 * @return {!Object}
 */
proto.MatchPmd.tagMatchRewardInfo.toObject = function(includeInstance, msg) {
  var f, obj = {
    wrankid: jspb.Message.getFieldWithDefault(msg, 1, 0),
    lrewardgold: jspb.Message.getFieldWithDefault(msg, 2, 0),
    lrewardingot: jspb.Message.getFieldWithDefault(msg, 3, 0),
    dwrewardexperience: jspb.Message.getFieldWithDefault(msg, 4, 0),
    respcmd: (f = msg.getRespcmd()) && NullPmd_pb.response.toObject(includeInstance, f)
  };

  if (includeInstance) {
    obj.$jspbMessageInstance = msg;
  }
  return obj;
};
}


/**
 * Deserializes binary data (in protobuf wire format).
 * @param {jspb.ByteSource} bytes The bytes to deserialize.
 * @return {!proto.MatchPmd.tagMatchRewardInfo}
 */
proto.MatchPmd.tagMatchRewardInfo.deserializeBinary = function(bytes) {
  var reader = new jspb.BinaryReader(bytes);
  var msg = new proto.MatchPmd.tagMatchRewardInfo;
  return proto.MatchPmd.tagMatchRewardInfo.deserializeBinaryFromReader(msg, reader);
};


/**
 * Deserializes binary data (in protobuf wire format) from the
 * given reader into the given message object.
 * @param {!proto.MatchPmd.tagMatchRewardInfo} msg The message object to deserialize into.
 * @param {!jspb.BinaryReader} reader The BinaryReader to use.
 * @return {!proto.MatchPmd.tagMatchRewardInfo}
 */
proto.MatchPmd.tagMatchRewardInfo.deserializeBinaryFromReader = function(msg, reader) {
  while (reader.nextField()) {
    if (reader.isEndGroup()) {
      break;
    }
    var field = reader.getFieldNumber();
    switch (field) {
    case 1:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setWrankid(value);
      break;
    case 2:
      var value = /** @type {number} */ (reader.readUint64());
      msg.setLrewardgold(value);
      break;
    case 3:
      var value = /** @type {number} */ (reader.readUint64());
      msg.setLrewardingot(value);
      break;
    case 4:
      var value = /** @type {number} */ (reader.readUint64());
      msg.setDwrewardexperience(value);
      break;
    case 5:
      var value = new NullPmd_pb.response;
      reader.readMessage(value,NullPmd_pb.response.deserializeBinaryFromReader);
      msg.setRespcmd(value);
      break;
    default:
      reader.skipField();
      break;
    }
  }
  return msg;
};


/**
 * Serializes the message to binary data (in protobuf wire format).
 * @return {!Uint8Array}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.serializeBinary = function() {
  var writer = new jspb.BinaryWriter();
  proto.MatchPmd.tagMatchRewardInfo.serializeBinaryToWriter(this, writer);
  return writer.getResultBuffer();
};


/**
 * Serializes the given message to binary data (in protobuf wire
 * format), writing to the given BinaryWriter.
 * @param {!proto.MatchPmd.tagMatchRewardInfo} message
 * @param {!jspb.BinaryWriter} writer
 */
proto.MatchPmd.tagMatchRewardInfo.serializeBinaryToWriter = function(message, writer) {
  var f = undefined;
  f = message.getWrankid();
  if (f !== 0) {
    writer.writeInt32(
      1,
      f
    );
  }
  f = message.getLrewardgold();
  if (f !== 0) {
    writer.writeUint64(
      2,
      f
    );
  }
  f = message.getLrewardingot();
  if (f !== 0) {
    writer.writeUint64(
      3,
      f
    );
  }
  f = message.getDwrewardexperience();
  if (f !== 0) {
    writer.writeUint64(
      4,
      f
    );
  }
  f = message.getRespcmd();
  if (f != null) {
    writer.writeMessage(
      5,
      f,
      NullPmd_pb.response.serializeBinaryToWriter
    );
  }
};


/**
 * optional int32 wrankid = 1;
 * @return {number}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.getWrankid = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 1, 0));
};


/** @param {number} value */
proto.MatchPmd.tagMatchRewardInfo.prototype.setWrankid = function(value) {
  jspb.Message.setField(this, 1, value);
};


/**
 * optional uint64 lrewardgold = 2;
 * @return {number}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.getLrewardgold = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 2, 0));
};


/** @param {number} value */
proto.MatchPmd.tagMatchRewardInfo.prototype.setLrewardgold = function(value) {
  jspb.Message.setField(this, 2, value);
};


/**
 * optional uint64 lrewardingot = 3;
 * @return {number}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.getLrewardingot = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 3, 0));
};


/** @param {number} value */
proto.MatchPmd.tagMatchRewardInfo.prototype.setLrewardingot = function(value) {
  jspb.Message.setField(this, 3, value);
};


/**
 * optional uint64 dwrewardexperience = 4;
 * @return {number}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.getDwrewardexperience = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 4, 0));
};


/** @param {number} value */
proto.MatchPmd.tagMatchRewardInfo.prototype.setDwrewardexperience = function(value) {
  jspb.Message.setField(this, 4, value);
};


/**
 * optional NullPmd.response respcmd = 5;
 * @return {?proto.NullPmd.response}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.getRespcmd = function() {
  return /** @type{?proto.NullPmd.response} */ (
    jspb.Message.getWrapperField(this, NullPmd_pb.response, 5));
};


/** @param {?proto.NullPmd.response|undefined} value */
proto.MatchPmd.tagMatchRewardInfo.prototype.setRespcmd = function(value) {
  jspb.Message.setWrapperField(this, 5, value);
};


proto.MatchPmd.tagMatchRewardInfo.prototype.clearRespcmd = function() {
  this.setRespcmd(undefined);
};


/**
 * Returns whether this field is set.
 * @return {!boolean}
 */
proto.MatchPmd.tagMatchRewardInfo.prototype.hasRespcmd = function() {
  return jspb.Message.getField(this, 5) != null;
};



/**
 * Generated by JsPbCodeGenerator.
 * @param {Array=} opt_data Optional initial data array, typically from a
 * server response, or constructed directly in Javascript. The array is used
 * in place and becomes part of the constructed object. It is not cloned.
 * If no data is provided, the constructed object will be empty, but still
 * valid.
 * @extends {jspb.Message}
 * @constructor
 */
proto.MatchPmd.tagGameMatch_s2c = function(opt_data) {
  jspb.Message.initialize(this, opt_data, 0, -1, proto.MatchPmd.tagGameMatch_s2c.repeatedFields_, null);
};
goog.inherits(proto.MatchPmd.tagGameMatch_s2c, jspb.Message);
if (goog.DEBUG && !COMPILED) {
  proto.MatchPmd.tagGameMatch_s2c.displayName = 'proto.MatchPmd.tagGameMatch_s2c';
}
/**
 * List of repeated fields within this message type.
 * @private {!Array<number>}
 * @const
 */
proto.MatchPmd.tagGameMatch_s2c.repeatedFields_ = [16];



if (jspb.Message.GENERATE_TO_OBJECT) {
/**
 * Creates an object representation of this proto suitable for use in Soy templates.
 * Field names that are reserved in JavaScript and will be renamed to pb_name.
 * To access a reserved field use, foo.pb_<name>, eg, foo.pb_default.
 * For the list of reserved names please see:
 *     com.google.apps.jspb.JsClassTemplate.JS_RESERVED_WORDS.
 * @param {boolean=} opt_includeInstance Whether to include the JSPB instance
 *     for transitional soy proto support: http://goto/soy-param-migration
 * @return {!Object}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.toObject = function(opt_includeInstance) {
  return proto.MatchPmd.tagGameMatch_s2c.toObject(opt_includeInstance, this);
};


/**
 * Static version of the {@see toObject} method.
 * @param {boolean|undefined} includeInstance Whether to include the JSPB
 *     instance for transitional soy proto support:
 *     http://goto/soy-param-migration
 * @param {!proto.MatchPmd.tagGameMatch_s2c} msg The msg instance to transform.
 * @return {!Object}
 */
proto.MatchPmd.tagGameMatch_s2c.toObject = function(includeInstance, msg) {
  var f, obj = {
    wserverid: jspb.Message.getFieldWithDefault(msg, 1, 0),
    dwmatchid: jspb.Message.getFieldWithDefault(msg, 2, 0),
    cbmatchtype: jspb.Message.getFieldWithDefault(msg, 3, 0),
    szmatchname: jspb.Message.getFieldWithDefault(msg, 4, ""),
    cbfeetype: jspb.Message.getFieldWithDefault(msg, 5, 0),
    cbdeductarea: jspb.Message.getFieldWithDefault(msg, 6, 0),
    lsignupfee: jspb.Message.getFieldWithDefault(msg, 7, 0),
    cbsignupmode: jspb.Message.getFieldWithDefault(msg, 8, 0),
    cbjoincondition: jspb.Message.getFieldWithDefault(msg, 9, 0),
    cbmemberorder: jspb.Message.getFieldWithDefault(msg, 10, 0),
    lexperience: jspb.Message.getFieldWithDefault(msg, 11, 0),
    cbrankingmode: jspb.Message.getFieldWithDefault(msg, 12, 0),
    wcountinnings: jspb.Message.getFieldWithDefault(msg, 13, 0),
    cbfiltergradesmode: jspb.Message.getFieldWithDefault(msg, 14, 0),
    wrewardcount: jspb.Message.getFieldWithDefault(msg, 15, 0),
    matchrewardinfoList: jspb.Message.toObjectList(msg.getMatchrewardinfoList(),
    proto.MatchPmd.tagMatchRewardInfo.toObject, includeInstance),
    cbmatchrule: jspb.Message.getFieldWithDefault(msg, 17, ""),
    respcmd: (f = msg.getRespcmd()) && NullPmd_pb.response.toObject(includeInstance, f)
  };

  if (includeInstance) {
    obj.$jspbMessageInstance = msg;
  }
  return obj;
};
}


/**
 * Deserializes binary data (in protobuf wire format).
 * @param {jspb.ByteSource} bytes The bytes to deserialize.
 * @return {!proto.MatchPmd.tagGameMatch_s2c}
 */
proto.MatchPmd.tagGameMatch_s2c.deserializeBinary = function(bytes) {
  var reader = new jspb.BinaryReader(bytes);
  var msg = new proto.MatchPmd.tagGameMatch_s2c;
  return proto.MatchPmd.tagGameMatch_s2c.deserializeBinaryFromReader(msg, reader);
};


/**
 * Deserializes binary data (in protobuf wire format) from the
 * given reader into the given message object.
 * @param {!proto.MatchPmd.tagGameMatch_s2c} msg The message object to deserialize into.
 * @param {!jspb.BinaryReader} reader The BinaryReader to use.
 * @return {!proto.MatchPmd.tagGameMatch_s2c}
 */
proto.MatchPmd.tagGameMatch_s2c.deserializeBinaryFromReader = function(msg, reader) {
  while (reader.nextField()) {
    if (reader.isEndGroup()) {
      break;
    }
    var field = reader.getFieldNumber();
    switch (field) {
    case 1:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setWserverid(value);
      break;
    case 2:
      var value = /** @type {number} */ (reader.readUint64());
      msg.setDwmatchid(value);
      break;
    case 3:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbmatchtype(value);
      break;
    case 4:
      var value = /** @type {string} */ (reader.readString());
      msg.setSzmatchname(value);
      break;
    case 5:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbfeetype(value);
      break;
    case 6:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbdeductarea(value);
      break;
    case 7:
      var value = /** @type {number} */ (reader.readUint64());
      msg.setLsignupfee(value);
      break;
    case 8:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbsignupmode(value);
      break;
    case 9:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbjoincondition(value);
      break;
    case 10:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbmemberorder(value);
      break;
    case 11:
      var value = /** @type {number} */ (reader.readUint64());
      msg.setLexperience(value);
      break;
    case 12:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbrankingmode(value);
      break;
    case 13:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setWcountinnings(value);
      break;
    case 14:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setCbfiltergradesmode(value);
      break;
    case 15:
      var value = /** @type {number} */ (reader.readInt32());
      msg.setWrewardcount(value);
      break;
    case 16:
      var value = new proto.MatchPmd.tagMatchRewardInfo;
      reader.readMessage(value,proto.MatchPmd.tagMatchRewardInfo.deserializeBinaryFromReader);
      msg.addMatchrewardinfo(value);
      break;
    case 17:
      var value = /** @type {string} */ (reader.readString());
      msg.setCbmatchrule(value);
      break;
    case 18:
      var value = new NullPmd_pb.response;
      reader.readMessage(value,NullPmd_pb.response.deserializeBinaryFromReader);
      msg.setRespcmd(value);
      break;
    default:
      reader.skipField();
      break;
    }
  }
  return msg;
};


/**
 * Serializes the message to binary data (in protobuf wire format).
 * @return {!Uint8Array}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.serializeBinary = function() {
  var writer = new jspb.BinaryWriter();
  proto.MatchPmd.tagGameMatch_s2c.serializeBinaryToWriter(this, writer);
  return writer.getResultBuffer();
};


/**
 * Serializes the given message to binary data (in protobuf wire
 * format), writing to the given BinaryWriter.
 * @param {!proto.MatchPmd.tagGameMatch_s2c} message
 * @param {!jspb.BinaryWriter} writer
 */
proto.MatchPmd.tagGameMatch_s2c.serializeBinaryToWriter = function(message, writer) {
  var f = undefined;
  f = message.getWserverid();
  if (f !== 0) {
    writer.writeInt32(
      1,
      f
    );
  }
  f = message.getDwmatchid();
  if (f !== 0) {
    writer.writeUint64(
      2,
      f
    );
  }
  f = message.getCbmatchtype();
  if (f !== 0) {
    writer.writeInt32(
      3,
      f
    );
  }
  f = message.getSzmatchname();
  if (f.length > 0) {
    writer.writeString(
      4,
      f
    );
  }
  f = message.getCbfeetype();
  if (f !== 0) {
    writer.writeInt32(
      5,
      f
    );
  }
  f = message.getCbdeductarea();
  if (f !== 0) {
    writer.writeInt32(
      6,
      f
    );
  }
  f = message.getLsignupfee();
  if (f !== 0) {
    writer.writeUint64(
      7,
      f
    );
  }
  f = message.getCbsignupmode();
  if (f !== 0) {
    writer.writeInt32(
      8,
      f
    );
  }
  f = message.getCbjoincondition();
  if (f !== 0) {
    writer.writeInt32(
      9,
      f
    );
  }
  f = message.getCbmemberorder();
  if (f !== 0) {
    writer.writeInt32(
      10,
      f
    );
  }
  f = message.getLexperience();
  if (f !== 0) {
    writer.writeUint64(
      11,
      f
    );
  }
  f = message.getCbrankingmode();
  if (f !== 0) {
    writer.writeInt32(
      12,
      f
    );
  }
  f = message.getWcountinnings();
  if (f !== 0) {
    writer.writeInt32(
      13,
      f
    );
  }
  f = message.getCbfiltergradesmode();
  if (f !== 0) {
    writer.writeInt32(
      14,
      f
    );
  }
  f = message.getWrewardcount();
  if (f !== 0) {
    writer.writeInt32(
      15,
      f
    );
  }
  f = message.getMatchrewardinfoList();
  if (f.length > 0) {
    writer.writeRepeatedMessage(
      16,
      f,
      proto.MatchPmd.tagMatchRewardInfo.serializeBinaryToWriter
    );
  }
  f = message.getCbmatchrule();
  if (f.length > 0) {
    writer.writeString(
      17,
      f
    );
  }
  f = message.getRespcmd();
  if (f != null) {
    writer.writeMessage(
      18,
      f,
      NullPmd_pb.response.serializeBinaryToWriter
    );
  }
};


/**
 * optional int32 wserverid = 1;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getWserverid = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 1, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setWserverid = function(value) {
  jspb.Message.setField(this, 1, value);
};


/**
 * optional uint64 dwmatchid = 2;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getDwmatchid = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 2, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setDwmatchid = function(value) {
  jspb.Message.setField(this, 2, value);
};


/**
 * optional int32 cbmatchtype = 3;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbmatchtype = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 3, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbmatchtype = function(value) {
  jspb.Message.setField(this, 3, value);
};


/**
 * optional string szmatchname = 4;
 * @return {string}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getSzmatchname = function() {
  return /** @type {string} */ (jspb.Message.getFieldWithDefault(this, 4, ""));
};


/** @param {string} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setSzmatchname = function(value) {
  jspb.Message.setField(this, 4, value);
};


/**
 * optional int32 cbfeetype = 5;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbfeetype = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 5, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbfeetype = function(value) {
  jspb.Message.setField(this, 5, value);
};


/**
 * optional int32 cbdeductarea = 6;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbdeductarea = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 6, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbdeductarea = function(value) {
  jspb.Message.setField(this, 6, value);
};


/**
 * optional uint64 lsignupfee = 7;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getLsignupfee = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 7, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setLsignupfee = function(value) {
  jspb.Message.setField(this, 7, value);
};


/**
 * optional int32 cbsignupmode = 8;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbsignupmode = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 8, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbsignupmode = function(value) {
  jspb.Message.setField(this, 8, value);
};


/**
 * optional int32 cbjoincondition = 9;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbjoincondition = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 9, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbjoincondition = function(value) {
  jspb.Message.setField(this, 9, value);
};


/**
 * optional int32 cbmemberorder = 10;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbmemberorder = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 10, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbmemberorder = function(value) {
  jspb.Message.setField(this, 10, value);
};


/**
 * optional uint64 lexperience = 11;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getLexperience = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 11, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setLexperience = function(value) {
  jspb.Message.setField(this, 11, value);
};


/**
 * optional int32 cbrankingmode = 12;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbrankingmode = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 12, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbrankingmode = function(value) {
  jspb.Message.setField(this, 12, value);
};


/**
 * optional int32 wcountinnings = 13;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getWcountinnings = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 13, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setWcountinnings = function(value) {
  jspb.Message.setField(this, 13, value);
};


/**
 * optional int32 cbfiltergradesmode = 14;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbfiltergradesmode = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 14, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbfiltergradesmode = function(value) {
  jspb.Message.setField(this, 14, value);
};


/**
 * optional int32 wrewardcount = 15;
 * @return {number}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getWrewardcount = function() {
  return /** @type {number} */ (jspb.Message.getFieldWithDefault(this, 15, 0));
};


/** @param {number} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setWrewardcount = function(value) {
  jspb.Message.setField(this, 15, value);
};


/**
 * repeated tagMatchRewardInfo matchrewardinfo = 16;
 * If you change this array by adding, removing or replacing elements, or if you
 * replace the array itself, then you must call the setter to update it.
 * @return {!Array.<!proto.MatchPmd.tagMatchRewardInfo>}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getMatchrewardinfoList = function() {
  return /** @type{!Array.<!proto.MatchPmd.tagMatchRewardInfo>} */ (
    jspb.Message.getRepeatedWrapperField(this, proto.MatchPmd.tagMatchRewardInfo, 16));
};


/** @param {!Array.<!proto.MatchPmd.tagMatchRewardInfo>} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setMatchrewardinfoList = function(value) {
  jspb.Message.setRepeatedWrapperField(this, 16, value);
};


/**
 * @param {!proto.MatchPmd.tagMatchRewardInfo=} opt_value
 * @param {number=} opt_index
 * @return {!proto.MatchPmd.tagMatchRewardInfo}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.addMatchrewardinfo = function(opt_value, opt_index) {
  return jspb.Message.addToRepeatedWrapperField(this, 16, opt_value, proto.MatchPmd.tagMatchRewardInfo, opt_index);
};


proto.MatchPmd.tagGameMatch_s2c.prototype.clearMatchrewardinfoList = function() {
  this.setMatchrewardinfoList([]);
};


/**
 * optional string cbmatchrule = 17;
 * @return {string}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getCbmatchrule = function() {
  return /** @type {string} */ (jspb.Message.getFieldWithDefault(this, 17, ""));
};


/** @param {string} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setCbmatchrule = function(value) {
  jspb.Message.setField(this, 17, value);
};


/**
 * optional NullPmd.response respcmd = 18;
 * @return {?proto.NullPmd.response}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.getRespcmd = function() {
  return /** @type{?proto.NullPmd.response} */ (
    jspb.Message.getWrapperField(this, NullPmd_pb.response, 18));
};


/** @param {?proto.NullPmd.response|undefined} value */
proto.MatchPmd.tagGameMatch_s2c.prototype.setRespcmd = function(value) {
  jspb.Message.setWrapperField(this, 18, value);
};


proto.MatchPmd.tagGameMatch_s2c.prototype.clearRespcmd = function() {
  this.setRespcmd(undefined);
};


/**
 * Returns whether this field is set.
 * @return {!boolean}
 */
proto.MatchPmd.tagGameMatch_s2c.prototype.hasRespcmd = function() {
  return jspb.Message.getField(this, 18) != null;
};


goog.object.extend(exports, proto.MatchPmd);
