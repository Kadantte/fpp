// ======================================================================
// \title  S1SerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for S1 struct
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "S1SerializableAc.hpp"

namespace M {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  S1 ::
    S1() :
      Serializable(),
      m_mF32(0.0f),
      m_mF64(0.0),
      m_mI16(0),
      m_mI32(0),
      m_mI64(0),
      m_mI8(0),
      m_mU16(0),
      m_mU32(0),
      m_mU64(0),
      m_mU8(0),
      m_mBool(false),
      m_mString(Fw::String(""))
  {

  }

  S1 ::
    S1(
        F32 mF32,
        F64 mF64,
        I16 mI16,
        I32 mI32,
        I64 mI64,
        I8 mI8,
        U16 mU16,
        U32 mU32,
        U64 mU64,
        U8 mU8,
        bool mBool,
        const Fw::StringBase& mString
    ) :
      Serializable(),
      m_mF32(mF32),
      m_mF64(mF64),
      m_mI16(mI16),
      m_mI32(mI32),
      m_mI64(mI64),
      m_mI8(mI8),
      m_mU16(mU16),
      m_mU32(mU32),
      m_mU64(mU64),
      m_mU8(mU8),
      m_mBool(mBool),
      m_mString(mString)
  {

  }

  S1 ::
    S1(const S1& obj) :
      Serializable(),
      m_mF32(obj.m_mF32),
      m_mF64(obj.m_mF64),
      m_mI16(obj.m_mI16),
      m_mI32(obj.m_mI32),
      m_mI64(obj.m_mI64),
      m_mI8(obj.m_mI8),
      m_mU16(obj.m_mU16),
      m_mU32(obj.m_mU32),
      m_mU64(obj.m_mU64),
      m_mU8(obj.m_mU8),
      m_mBool(obj.m_mBool),
      m_mString(obj.m_mString)
  {

  }

  // ----------------------------------------------------------------------
  // Operators
  // ----------------------------------------------------------------------

  S1& S1 ::
    operator=(const S1& obj)
  {
    if (this == &obj) {
      return *this;
    }

    set(obj.m_mF32, obj.m_mF64, obj.m_mI16, obj.m_mI32, obj.m_mI64, obj.m_mI8, obj.m_mU16, obj.m_mU32, obj.m_mU64, obj.m_mU8, obj.m_mBool, obj.m_mString);
    return *this;
  }

  bool S1 ::
    operator==(const S1& obj) const
  {
    return (
      (this->m_mF32 == obj.m_mF32) &&
      (this->m_mF64 == obj.m_mF64) &&
      (this->m_mI16 == obj.m_mI16) &&
      (this->m_mI32 == obj.m_mI32) &&
      (this->m_mI64 == obj.m_mI64) &&
      (this->m_mI8 == obj.m_mI8) &&
      (this->m_mU16 == obj.m_mU16) &&
      (this->m_mU32 == obj.m_mU32) &&
      (this->m_mU64 == obj.m_mU64) &&
      (this->m_mU8 == obj.m_mU8) &&
      (this->m_mBool == obj.m_mBool) &&
      (this->m_mString == obj.m_mString)
    );
  }

  bool S1 ::
    operator!=(const S1& obj) const
  {
    return !(*this == obj);
  }

#ifdef BUILD_UT

  std::ostream& operator<<(std::ostream& os, const S1& obj) {
    Fw::String s;
    obj.toString(s);
    os << s.toChar();
    return os;
  }

#endif

  // ----------------------------------------------------------------------
  // Member functions
  // ----------------------------------------------------------------------

  Fw::SerializeStatus S1 ::
    serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;

    status = buffer.serialize(this->m_mF32);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mF64);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mI16);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mI32);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mI64);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mI8);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mU16);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mU32);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mU64);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mU8);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mBool);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.serialize(this->m_mString);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }

    return status;
  }

  Fw::SerializeStatus S1 ::
    deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;

    status = buffer.deserialize(this->m_mF32);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mF64);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mI16);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mI32);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mI64);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mI8);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mU16);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mU32);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mU64);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mU8);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mBool);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
    status = buffer.deserialize(this->m_mString);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }

    return status;
  }

#if FW_SERIALIZABLE_TO_STRING

  void S1 ::
    toString(Fw::StringBase& sb) const
  {
    static const char* formatString =
      "( "
      "mF32 = %f, "
      "mF64 = %f, "
      "mI16 = %" PRIi16 ", "
      "mI32 = %" PRIi32 ", "
      "mI64 = %" PRIi64 ", "
      "mI8 = %" PRIi8 ", "
      "mU16 = %" PRIu16 ", "
      "mU32 = %" PRIu32 ", "
      "mU64 = %" PRIu64 ", "
      "mU8 = %" PRIu8 ", "
      "mBool = %d, "
      "mString = %s"
      " )";

    sb.format(
      formatString,
      this->m_mF32,
      this->m_mF64,
      this->m_mI16,
      this->m_mI32,
      this->m_mI64,
      this->m_mI8,
      this->m_mU16,
      this->m_mU32,
      this->m_mU64,
      this->m_mU8,
      this->m_mBool,
      this->m_mString.toChar()
    );
  }

#endif

  // ----------------------------------------------------------------------
  // Setter functions
  // ----------------------------------------------------------------------

  void S1 ::
    set(
        F32 mF32,
        F64 mF64,
        I16 mI16,
        I32 mI32,
        I64 mI64,
        I8 mI8,
        U16 mU16,
        U32 mU32,
        U64 mU64,
        U8 mU8,
        bool mBool,
        const Fw::StringBase& mString
    )
  {
    this->m_mF32 = mF32;
    this->m_mF64 = mF64;
    this->m_mI16 = mI16;
    this->m_mI32 = mI32;
    this->m_mI64 = mI64;
    this->m_mI8 = mI8;
    this->m_mU16 = mU16;
    this->m_mU32 = mU32;
    this->m_mU64 = mU64;
    this->m_mU8 = mU8;
    this->m_mBool = mBool;
    this->m_mString = mString;
  }

  void S1 ::
    setmF32(F32 mF32)
  {
    this->m_mF32 = mF32;
  }

  void S1 ::
    setmF64(F64 mF64)
  {
    this->m_mF64 = mF64;
  }

  void S1 ::
    setmI16(I16 mI16)
  {
    this->m_mI16 = mI16;
  }

  void S1 ::
    setmI32(I32 mI32)
  {
    this->m_mI32 = mI32;
  }

  void S1 ::
    setmI64(I64 mI64)
  {
    this->m_mI64 = mI64;
  }

  void S1 ::
    setmI8(I8 mI8)
  {
    this->m_mI8 = mI8;
  }

  void S1 ::
    setmU16(U16 mU16)
  {
    this->m_mU16 = mU16;
  }

  void S1 ::
    setmU32(U32 mU32)
  {
    this->m_mU32 = mU32;
  }

  void S1 ::
    setmU64(U64 mU64)
  {
    this->m_mU64 = mU64;
  }

  void S1 ::
    setmU8(U8 mU8)
  {
    this->m_mU8 = mU8;
  }

  void S1 ::
    setmBool(bool mBool)
  {
    this->m_mBool = mBool;
  }

  void S1 ::
    setmString(const Fw::StringBase& mString)
  {
    this->m_mString = mString;
  }

}
