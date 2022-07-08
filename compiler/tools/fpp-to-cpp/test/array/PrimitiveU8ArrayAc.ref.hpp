// ======================================================================
// \title  PrimitiveU8ArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PrimitiveU8 array
// ======================================================================

#ifndef M_PrimitiveU8ArrayAc_HPP
#define M_PrimitiveU8ArrayAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

namespace M {

  class PrimitiveU8 :
    public Fw::Serializable
  {

    public:

      // ----------------------------------------------------------------------
      // Types
      // ----------------------------------------------------------------------

      //! The element type
      typedef U8 ElementType;

    public:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      enum {
        //! The size of the array
        SIZE = 3,
        //! The size of the serial representation
        SERIALIZED_SIZE = SIZE * sizeof(U8),
      };

    public:

      // ----------------------------------------------------------------------
      // Constructors
      // ----------------------------------------------------------------------

      //! Constructor (default value)
      PrimitiveU8();

      //! Constructor (user-provided value)
      PrimitiveU8(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Constructor (single element)
      PrimitiveU8(
          const ElementType& e //!< The element
      );

      //! Constructor (multiple elements)
      PrimitiveU8(
          const ElementType& e1, //!< Element 1
          const ElementType& e2, //!< Element 2
          const ElementType& e3 //!< Element 3
      );

      //! Copy Constructor
      PrimitiveU8(
          const PrimitiveU8& obj //!< The source object
      );

    public:

      // ----------------------------------------------------------------------
      // Operators
      // ----------------------------------------------------------------------

      //! Subscript operator
      ElementType& operator[](
          const U32 i //!< The subscript index
      );

      //! Const subscript operator
      const ElementType& operator[](
          const U32 i //!< The subscript index
      ) const;

      //! Copy assignment operator (object)
      PrimitiveU8& operator=(
          const PrimitiveU8& obj //!< The source object
      );

      //! Copy assignment operator (raw array)
      PrimitiveU8& operator=(
          const ElementType (&a)[SIZE] //!< The source array
      );

      //! Copy assignment operator (single element)
      PrimitiveU8& operator=(
          const ElementType& e //!< The element
      );

      //! Equality operator
      bool operator==(
          const PrimitiveU8& obj //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const PrimitiveU8& obj //!< The other object
      ) const;

#ifdef BUILD_UT

      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const PrimitiveU8& obj //!< The object
      );

#endif

    public:

      // ----------------------------------------------------------------------
      // Member functions
      // ----------------------------------------------------------------------

      //! Serialization
      Fw::SerializeStatus serialize(
          Fw::SerializeBufferBase& buffer //!< The serial buffer
      ) const;

      //! Deserialization
      Fw::SerializeStatus deserialize(
          Fw::SerializeBufferBase& buffer //!< The serial buffer
      );

#if FW_ARRAY_TO_STRING || BUILD_UT

      //! Convert array to string
      void toString(
          Fw::StringBase& sb //!< The StringBase object to hold the result
      ) const;

#endif

    private:

      // ----------------------------------------------------------------------
      // Member variables
      // ----------------------------------------------------------------------

      //! The array elements
      ElementType elements[SIZE];

  };

}

#endif
