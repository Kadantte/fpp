// ======================================================================
// \title  S2SerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for S2 struct
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "S2SerializableAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

S2 ::
  S2() :
    Serializable(),
    m_s1(0.0f, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, false, Fw::String(""))
{

}

S2 ::
  S2(const M::S1& s1) :
    Serializable(),
    m_s1(s1)
{

}

S2 ::
  S2(const S2& obj) :
    Serializable(),
    m_s1(obj.m_s1)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

S2& S2 ::
  operator=(const S2& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_s1);
  return *this;
}

bool S2 ::
  operator==(const S2& obj) const
{
  return (this->m_s1 == obj.m_s1);
}

bool S2 ::
  operator!=(const S2& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const S2& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus S2 ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_s1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus S2 ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_s1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void S2 ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "s1 = %s"
    " )";

  // Declare strings to hold any serializable toString() arguments
  Fw::String s1Str;

  // Call toString for arrays and serializable types
  this->m_s1.toString(s1Str);

  sb.format(
    formatString,
    s1Str.toChar()
  );
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void S2 ::
  set(const M::S1& s1)
{
  this->m_s1 = s1;
}

void S2 ::
  sets1(const M::S1& s1)
{
  this->m_s1 = s1;
}
