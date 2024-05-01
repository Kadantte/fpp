// ======================================================================
// \title  PrimitiveF64ArrayAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PrimitiveF64 array
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "PrimitiveF64ArrayAc.hpp"

namespace M {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  PrimitiveF64 ::
    PrimitiveF64() :
      Serializable()
  {
    // Construct using element-wise constructor
    *this = PrimitiveF64(
      1.0,
      2.0,
      3.0,
      4.0,
      5.0
    );
  }

  PrimitiveF64 ::
    PrimitiveF64(const ElementType (&a)[SIZE]) :
      Serializable()
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = a[index];
    }
  }

  PrimitiveF64 ::
    PrimitiveF64(const ElementType& e) :
      Serializable()
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = e;
    }
  }

  PrimitiveF64 ::
    PrimitiveF64(
        const ElementType& e1,
        const ElementType& e2,
        const ElementType& e3,
        const ElementType& e4,
        const ElementType& e5
    ) :
      Serializable()
  {
    this->elements[0] = e1;
    this->elements[1] = e2;
    this->elements[2] = e3;
    this->elements[3] = e4;
    this->elements[4] = e5;
  }

  PrimitiveF64 ::
    PrimitiveF64(const PrimitiveF64& obj) :
      Serializable()
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = obj.elements[index];
    }
  }

  // ----------------------------------------------------------------------
  // Operators
  // ----------------------------------------------------------------------

  PrimitiveF64::ElementType& PrimitiveF64 ::
    operator[](const U32 i)
  {
    FW_ASSERT(i < SIZE, static_cast<FwAssertArgType>(i), static_cast<FwAssertArgType>(SIZE));
    return this->elements[i];
  }

  const PrimitiveF64::ElementType& PrimitiveF64 ::
    operator[](const U32 i) const
  {
    FW_ASSERT(i < SIZE, static_cast<FwAssertArgType>(i), static_cast<FwAssertArgType>(SIZE));
    return this->elements[i];
  }

  PrimitiveF64& PrimitiveF64 ::
    operator=(const PrimitiveF64& obj)
  {
    if (this == &obj) {
      return *this;
    }

    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = obj.elements[index];
    }
    return *this;
  }

  PrimitiveF64& PrimitiveF64 ::
    operator=(const ElementType (&a)[SIZE])
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = a[index];
    }
    return *this;
  }

  PrimitiveF64& PrimitiveF64 ::
    operator=(const ElementType& e)
  {
    for (U32 index = 0; index < SIZE; index++) {
      this->elements[index] = e;
    }
    return *this;
  }

  bool PrimitiveF64 ::
    operator==(const PrimitiveF64& obj) const
  {
    for (U32 index = 0; index < SIZE; index++) {
      if (!((*this)[index] == obj[index])) {
        return false;
      }
    }
    return true;
  }

  bool PrimitiveF64 ::
    operator!=(const PrimitiveF64& obj) const
  {
    return !(*this == obj);
  }

#ifdef BUILD_UT

  std::ostream& operator<<(std::ostream& os, const PrimitiveF64& obj) {
    Fw::String s;
    obj.toString(s);
    os << s;
    return os;
  }

#endif

  // ----------------------------------------------------------------------
  // Member functions
  // ----------------------------------------------------------------------

  Fw::SerializeStatus PrimitiveF64 ::
    serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    for (U32 index = 0; index < SIZE; index++) {
      status = buffer.serialize((*this)[index]);
      if (status != Fw::FW_SERIALIZE_OK) {
        return status;
      }
    }
    return status;
  }

  Fw::SerializeStatus PrimitiveF64 ::
    deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    for (U32 index = 0; index < SIZE; index++) {
      status = buffer.deserialize((*this)[index]);
      if (status != Fw::FW_SERIALIZE_OK) {
        return status;
      }
    }
    return status;
  }

#if FW_ARRAY_TO_STRING

  void PrimitiveF64 ::
    toString(Fw::StringBase& sb) const
  {
    static const char *formatString = "[ "
      "%.5g "
      "%.5g "
      "%.5g "
      "%.5g "
      "%.5g ]";

    sb.format(
      formatString,
      this->elements[0],
      this->elements[1],
      this->elements[2],
      this->elements[3],
      this->elements[4]
    );
  }

#endif

}
