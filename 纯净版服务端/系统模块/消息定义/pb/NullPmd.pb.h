// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NullPmd.proto

#ifndef PROTOBUF_NullPmd_2eproto__INCLUDED
#define PROTOBUF_NullPmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace NullPmd {
class command;
class commandDefaultTypeInternal;
extern commandDefaultTypeInternal _command_default_instance_;
class head;
class headDefaultTypeInternal;
extern headDefaultTypeInternal _head_default_instance_;
class indication;
class indicationDefaultTypeInternal;
extern indicationDefaultTypeInternal _indication_default_instance_;
class info;
class infoDefaultTypeInternal;
extern infoDefaultTypeInternal _info_default_instance_;
class message;
class messageDefaultTypeInternal;
extern messageDefaultTypeInternal _message_default_instance_;
class request;
class requestDefaultTypeInternal;
extern requestDefaultTypeInternal _request_default_instance_;
class response;
class responseDefaultTypeInternal;
extern responseDefaultTypeInternal _response_default_instance_;
}  // namespace NullPmd

namespace NullPmd {

namespace protobuf_NullPmd_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_NullPmd_2eproto

// ===================================================================

class request : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.request) */ {
 public:
  request();
  virtual ~request();

  request(const request& from);

  inline request& operator=(const request& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const request& default_instance();

  static inline const request* internal_default_instance() {
    return reinterpret_cast<const request*>(
               &_request_default_instance_);
  }

  void Swap(request* other);

  // implements Message ----------------------------------------------

  inline request* New() const PROTOBUF_FINAL { return New(NULL); }

  request* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const request& from);
  void MergeFrom(const request& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(request* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:NullPmd.request)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class response : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.response) */ {
 public:
  response();
  virtual ~response();

  response(const response& from);

  inline response& operator=(const response& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const response& default_instance();

  static inline const response* internal_default_instance() {
    return reinterpret_cast<const response*>(
               &_response_default_instance_);
  }

  void Swap(response* other);

  // implements Message ----------------------------------------------

  inline response* New() const PROTOBUF_FINAL { return New(NULL); }

  response* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const response& from);
  void MergeFrom(const response& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(response* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string errordescription = 2;
  void clear_errordescription();
  static const int kErrordescriptionFieldNumber = 2;
  const ::std::string& errordescription() const;
  void set_errordescription(const ::std::string& value);
  #if LANG_CXX11
  void set_errordescription(::std::string&& value);
  #endif
  void set_errordescription(const char* value);
  void set_errordescription(const char* value, size_t size);
  ::std::string* mutable_errordescription();
  ::std::string* release_errordescription();
  void set_allocated_errordescription(::std::string* errordescription);

  // int32 result = 1;
  void clear_result();
  static const int kResultFieldNumber = 1;
  ::google::protobuf::int32 result() const;
  void set_result(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:NullPmd.response)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr errordescription_;
  ::google::protobuf::int32 result_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class indication : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.indication) */ {
 public:
  indication();
  virtual ~indication();

  indication(const indication& from);

  inline indication& operator=(const indication& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const indication& default_instance();

  static inline const indication* internal_default_instance() {
    return reinterpret_cast<const indication*>(
               &_indication_default_instance_);
  }

  void Swap(indication* other);

  // implements Message ----------------------------------------------

  inline indication* New() const PROTOBUF_FINAL { return New(NULL); }

  indication* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const indication& from);
  void MergeFrom(const indication& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(indication* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:NullPmd.indication)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class command : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.command) */ {
 public:
  command();
  virtual ~command();

  command(const command& from);

  inline command& operator=(const command& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const command& default_instance();

  static inline const command* internal_default_instance() {
    return reinterpret_cast<const command*>(
               &_command_default_instance_);
  }

  void Swap(command* other);

  // implements Message ----------------------------------------------

  inline command* New() const PROTOBUF_FINAL { return New(NULL); }

  command* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const command& from);
  void MergeFrom(const command& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(command* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 mainid = 1;
  void clear_mainid();
  static const int kMainidFieldNumber = 1;
  ::google::protobuf::uint64 mainid() const;
  void set_mainid(::google::protobuf::uint64 value);

  // uint64 subid = 2;
  void clear_subid();
  static const int kSubidFieldNumber = 2;
  ::google::protobuf::uint64 subid() const;
  void set_subid(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:NullPmd.command)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 mainid_;
  ::google::protobuf::uint64 subid_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class info : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.info) */ {
 public:
  info();
  virtual ~info();

  info(const info& from);

  inline info& operator=(const info& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const info& default_instance();

  static inline const info* internal_default_instance() {
    return reinterpret_cast<const info*>(
               &_info_default_instance_);
  }

  void Swap(info* other);

  // implements Message ----------------------------------------------

  inline info* New() const PROTOBUF_FINAL { return New(NULL); }

  info* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const info& from);
  void MergeFrom(const info& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(info* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 cbversion = 1;
  void clear_cbversion();
  static const int kCbversionFieldNumber = 1;
  ::google::protobuf::uint64 cbversion() const;
  void set_cbversion(::google::protobuf::uint64 value);

  // uint64 cbcheckcode = 2;
  void clear_cbcheckcode();
  static const int kCbcheckcodeFieldNumber = 2;
  ::google::protobuf::uint64 cbcheckcode() const;
  void set_cbcheckcode(::google::protobuf::uint64 value);

  // uint64 wpacketsize = 3;
  void clear_wpacketsize();
  static const int kWpacketsizeFieldNumber = 3;
  ::google::protobuf::uint64 wpacketsize() const;
  void set_wpacketsize(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:NullPmd.info)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 cbversion_;
  ::google::protobuf::uint64 cbcheckcode_;
  ::google::protobuf::uint64 wpacketsize_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class head : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.head) */ {
 public:
  head();
  virtual ~head();

  head(const head& from);

  inline head& operator=(const head& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const head& default_instance();

  static inline const head* internal_default_instance() {
    return reinterpret_cast<const head*>(
               &_head_default_instance_);
  }

  void Swap(head* other);

  // implements Message ----------------------------------------------

  inline head* New() const PROTOBUF_FINAL { return New(NULL); }

  head* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const head& from);
  void MergeFrom(const head& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(head* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .NullPmd.command command = 1;
  bool has_command() const;
  void clear_command();
  static const int kCommandFieldNumber = 1;
  const ::NullPmd::command& command() const;
  ::NullPmd::command* mutable_command();
  ::NullPmd::command* release_command();
  void set_allocated_command(::NullPmd::command* command);

  // .NullPmd.info info = 2;
  bool has_info() const;
  void clear_info();
  static const int kInfoFieldNumber = 2;
  const ::NullPmd::info& info() const;
  ::NullPmd::info* mutable_info();
  ::NullPmd::info* release_info();
  void set_allocated_info(::NullPmd::info* info);

  // @@protoc_insertion_point(class_scope:NullPmd.head)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::NullPmd::command* command_;
  ::NullPmd::info* info_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class message : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NullPmd.message) */ {
 public:
  message();
  virtual ~message();

  message(const message& from);

  inline message& operator=(const message& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const message& default_instance();

  static inline const message* internal_default_instance() {
    return reinterpret_cast<const message*>(
               &_message_default_instance_);
  }

  void Swap(message* other);

  // implements Message ----------------------------------------------

  inline message* New() const PROTOBUF_FINAL { return New(NULL); }

  message* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const message& from);
  void MergeFrom(const message& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(message* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes data = 2;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // .NullPmd.head head = 1;
  bool has_head() const;
  void clear_head();
  static const int kHeadFieldNumber = 1;
  const ::NullPmd::head& head() const;
  ::NullPmd::head* mutable_head();
  ::NullPmd::head* release_head();
  void set_allocated_head(::NullPmd::head* head);

  // @@protoc_insertion_point(class_scope:NullPmd.message)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::NullPmd::head* head_;
  mutable int _cached_size_;
  friend struct  protobuf_NullPmd_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// request

// -------------------------------------------------------------------

// response

// int32 result = 1;
inline void response::clear_result() {
  result_ = 0;
}
inline ::google::protobuf::int32 response::result() const {
  // @@protoc_insertion_point(field_get:NullPmd.response.result)
  return result_;
}
inline void response::set_result(::google::protobuf::int32 value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:NullPmd.response.result)
}

// string errordescription = 2;
inline void response::clear_errordescription() {
  errordescription_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& response::errordescription() const {
  // @@protoc_insertion_point(field_get:NullPmd.response.errordescription)
  return errordescription_.GetNoArena();
}
inline void response::set_errordescription(const ::std::string& value) {
  
  errordescription_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NullPmd.response.errordescription)
}
#if LANG_CXX11
inline void response::set_errordescription(::std::string&& value) {
  
  errordescription_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NullPmd.response.errordescription)
}
#endif
inline void response::set_errordescription(const char* value) {
  
  errordescription_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NullPmd.response.errordescription)
}
inline void response::set_errordescription(const char* value, size_t size) {
  
  errordescription_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NullPmd.response.errordescription)
}
inline ::std::string* response::mutable_errordescription() {
  
  // @@protoc_insertion_point(field_mutable:NullPmd.response.errordescription)
  return errordescription_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* response::release_errordescription() {
  // @@protoc_insertion_point(field_release:NullPmd.response.errordescription)
  
  return errordescription_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void response::set_allocated_errordescription(::std::string* errordescription) {
  if (errordescription != NULL) {
    
  } else {
    
  }
  errordescription_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), errordescription);
  // @@protoc_insertion_point(field_set_allocated:NullPmd.response.errordescription)
}

// -------------------------------------------------------------------

// indication

// -------------------------------------------------------------------

// command

// uint64 mainid = 1;
inline void command::clear_mainid() {
  mainid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 command::mainid() const {
  // @@protoc_insertion_point(field_get:NullPmd.command.mainid)
  return mainid_;
}
inline void command::set_mainid(::google::protobuf::uint64 value) {
  
  mainid_ = value;
  // @@protoc_insertion_point(field_set:NullPmd.command.mainid)
}

// uint64 subid = 2;
inline void command::clear_subid() {
  subid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 command::subid() const {
  // @@protoc_insertion_point(field_get:NullPmd.command.subid)
  return subid_;
}
inline void command::set_subid(::google::protobuf::uint64 value) {
  
  subid_ = value;
  // @@protoc_insertion_point(field_set:NullPmd.command.subid)
}

// -------------------------------------------------------------------

// info

// uint64 cbversion = 1;
inline void info::clear_cbversion() {
  cbversion_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 info::cbversion() const {
  // @@protoc_insertion_point(field_get:NullPmd.info.cbversion)
  return cbversion_;
}
inline void info::set_cbversion(::google::protobuf::uint64 value) {
  
  cbversion_ = value;
  // @@protoc_insertion_point(field_set:NullPmd.info.cbversion)
}

// uint64 cbcheckcode = 2;
inline void info::clear_cbcheckcode() {
  cbcheckcode_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 info::cbcheckcode() const {
  // @@protoc_insertion_point(field_get:NullPmd.info.cbcheckcode)
  return cbcheckcode_;
}
inline void info::set_cbcheckcode(::google::protobuf::uint64 value) {
  
  cbcheckcode_ = value;
  // @@protoc_insertion_point(field_set:NullPmd.info.cbcheckcode)
}

// uint64 wpacketsize = 3;
inline void info::clear_wpacketsize() {
  wpacketsize_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 info::wpacketsize() const {
  // @@protoc_insertion_point(field_get:NullPmd.info.wpacketsize)
  return wpacketsize_;
}
inline void info::set_wpacketsize(::google::protobuf::uint64 value) {
  
  wpacketsize_ = value;
  // @@protoc_insertion_point(field_set:NullPmd.info.wpacketsize)
}

// -------------------------------------------------------------------

// head

// .NullPmd.command command = 1;
inline bool head::has_command() const {
  return this != internal_default_instance() && command_ != NULL;
}
inline void head::clear_command() {
  if (GetArenaNoVirtual() == NULL && command_ != NULL) delete command_;
  command_ = NULL;
}
inline const ::NullPmd::command& head::command() const {
  // @@protoc_insertion_point(field_get:NullPmd.head.command)
  return command_ != NULL ? *command_
                         : *::NullPmd::command::internal_default_instance();
}
inline ::NullPmd::command* head::mutable_command() {
  
  if (command_ == NULL) {
    command_ = new ::NullPmd::command;
  }
  // @@protoc_insertion_point(field_mutable:NullPmd.head.command)
  return command_;
}
inline ::NullPmd::command* head::release_command() {
  // @@protoc_insertion_point(field_release:NullPmd.head.command)
  
  ::NullPmd::command* temp = command_;
  command_ = NULL;
  return temp;
}
inline void head::set_allocated_command(::NullPmd::command* command) {
  delete command_;
  command_ = command;
  if (command) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NullPmd.head.command)
}

// .NullPmd.info info = 2;
inline bool head::has_info() const {
  return this != internal_default_instance() && info_ != NULL;
}
inline void head::clear_info() {
  if (GetArenaNoVirtual() == NULL && info_ != NULL) delete info_;
  info_ = NULL;
}
inline const ::NullPmd::info& head::info() const {
  // @@protoc_insertion_point(field_get:NullPmd.head.info)
  return info_ != NULL ? *info_
                         : *::NullPmd::info::internal_default_instance();
}
inline ::NullPmd::info* head::mutable_info() {
  
  if (info_ == NULL) {
    info_ = new ::NullPmd::info;
  }
  // @@protoc_insertion_point(field_mutable:NullPmd.head.info)
  return info_;
}
inline ::NullPmd::info* head::release_info() {
  // @@protoc_insertion_point(field_release:NullPmd.head.info)
  
  ::NullPmd::info* temp = info_;
  info_ = NULL;
  return temp;
}
inline void head::set_allocated_info(::NullPmd::info* info) {
  delete info_;
  info_ = info;
  if (info) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NullPmd.head.info)
}

// -------------------------------------------------------------------

// message

// .NullPmd.head head = 1;
inline bool message::has_head() const {
  return this != internal_default_instance() && head_ != NULL;
}
inline void message::clear_head() {
  if (GetArenaNoVirtual() == NULL && head_ != NULL) delete head_;
  head_ = NULL;
}
inline const ::NullPmd::head& message::head() const {
  // @@protoc_insertion_point(field_get:NullPmd.message.head)
  return head_ != NULL ? *head_
                         : *::NullPmd::head::internal_default_instance();
}
inline ::NullPmd::head* message::mutable_head() {
  
  if (head_ == NULL) {
    head_ = new ::NullPmd::head;
  }
  // @@protoc_insertion_point(field_mutable:NullPmd.message.head)
  return head_;
}
inline ::NullPmd::head* message::release_head() {
  // @@protoc_insertion_point(field_release:NullPmd.message.head)
  
  ::NullPmd::head* temp = head_;
  head_ = NULL;
  return temp;
}
inline void message::set_allocated_head(::NullPmd::head* head) {
  delete head_;
  head_ = head;
  if (head) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:NullPmd.message.head)
}

// bytes data = 2;
inline void message::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& message::data() const {
  // @@protoc_insertion_point(field_get:NullPmd.message.data)
  return data_.GetNoArena();
}
inline void message::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:NullPmd.message.data)
}
#if LANG_CXX11
inline void message::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:NullPmd.message.data)
}
#endif
inline void message::set_data(const char* value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:NullPmd.message.data)
}
inline void message::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:NullPmd.message.data)
}
inline ::std::string* message::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:NullPmd.message.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* message::release_data() {
  // @@protoc_insertion_point(field_release:NullPmd.message.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void message::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:NullPmd.message.data)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace NullPmd

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_NullPmd_2eproto__INCLUDED
