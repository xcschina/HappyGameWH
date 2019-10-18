// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DdzPmd.proto

#ifndef PROTOBUF_DdzPmd_2eproto__INCLUDED
#define PROTOBUF_DdzPmd_2eproto__INCLUDED

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
#include "NullPmd.pb.h"
// @@protoc_insertion_point(includes)
namespace DdzPmd {
class ddz_c2s;
class ddz_c2sDefaultTypeInternal;
extern ddz_c2sDefaultTypeInternal _ddz_c2s_default_instance_;
}  // namespace DdzPmd
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

namespace DdzPmd {

namespace protobuf_DdzPmd_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_DdzPmd_2eproto

// ===================================================================

class ddz_c2s : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DdzPmd.ddz_c2s) */ {
 public:
  ddz_c2s();
  virtual ~ddz_c2s();

  ddz_c2s(const ddz_c2s& from);

  inline ddz_c2s& operator=(const ddz_c2s& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ddz_c2s& default_instance();

  static inline const ddz_c2s* internal_default_instance() {
    return reinterpret_cast<const ddz_c2s*>(
               &_ddz_c2s_default_instance_);
  }

  void Swap(ddz_c2s* other);

  // implements Message ----------------------------------------------

  inline ddz_c2s* New() const PROTOBUF_FINAL { return New(NULL); }

  ddz_c2s* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ddz_c2s& from);
  void MergeFrom(const ddz_c2s& from);
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
  void InternalSwap(ddz_c2s* other);
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

  // .NullPmd.request reqcmd = 1;
  bool has_reqcmd() const;
  void clear_reqcmd();
  static const int kReqcmdFieldNumber = 1;
  const ::NullPmd::request& reqcmd() const;
  ::NullPmd::request* mutable_reqcmd();
  ::NullPmd::request* release_reqcmd();
  void set_allocated_reqcmd(::NullPmd::request* reqcmd);

  // @@protoc_insertion_point(class_scope:DdzPmd.ddz_c2s)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::NullPmd::request* reqcmd_;
  mutable int _cached_size_;
  friend struct  protobuf_DdzPmd_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ddz_c2s

// .NullPmd.request reqcmd = 1;
inline bool ddz_c2s::has_reqcmd() const {
  return this != internal_default_instance() && reqcmd_ != NULL;
}
inline void ddz_c2s::clear_reqcmd() {
  if (GetArenaNoVirtual() == NULL && reqcmd_ != NULL) delete reqcmd_;
  reqcmd_ = NULL;
}
inline const ::NullPmd::request& ddz_c2s::reqcmd() const {
  // @@protoc_insertion_point(field_get:DdzPmd.ddz_c2s.reqcmd)
  return reqcmd_ != NULL ? *reqcmd_
                         : *::NullPmd::request::internal_default_instance();
}
inline ::NullPmd::request* ddz_c2s::mutable_reqcmd() {
  
  if (reqcmd_ == NULL) {
    reqcmd_ = new ::NullPmd::request;
  }
  // @@protoc_insertion_point(field_mutable:DdzPmd.ddz_c2s.reqcmd)
  return reqcmd_;
}
inline ::NullPmd::request* ddz_c2s::release_reqcmd() {
  // @@protoc_insertion_point(field_release:DdzPmd.ddz_c2s.reqcmd)
  
  ::NullPmd::request* temp = reqcmd_;
  reqcmd_ = NULL;
  return temp;
}
inline void ddz_c2s::set_allocated_reqcmd(::NullPmd::request* reqcmd) {
  delete reqcmd_;
  reqcmd_ = reqcmd;
  if (reqcmd) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DdzPmd.ddz_c2s.reqcmd)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace DdzPmd

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_DdzPmd_2eproto__INCLUDED
