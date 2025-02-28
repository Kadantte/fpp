// ======================================================================
// \title  Struct1ArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Struct1 array
// ======================================================================

#ifndef Struct1ArrayAc_HPP
#define Struct1ArrayAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/ExternalString.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"
#include "S1SerializableAc.hpp"

//! An array of structs
class Struct1 :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The element type
    using ElementType = M::S1;

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the array
      SIZE = 5,
      //! The serialized size of each element
      ELEMENT_SERIALIZED_SIZE = M::S1::SERIALIZED_SIZE,
      //! The size of the serial representation
      SERIALIZED_SIZE = SIZE * ELEMENT_SERIALIZED_SIZE
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    Struct1();

    //! Constructor (user-provided value)
    Struct1(
        const ElementType (&a)[SIZE] //!< The array
    );

    //! Constructor (single element)
    Struct1(
        const ElementType& e //!< The element
    );

    //! Constructor (multiple elements)
    Struct1(
        const ElementType& e1, //!< Element 1
        const ElementType& e2, //!< Element 2
        const ElementType& e3, //!< Element 3
        const ElementType& e4, //!< Element 4
        const ElementType& e5 //!< Element 5
    );

    //! Copy Constructor
    Struct1(
        const Struct1& obj //!< The source object
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
    Struct1& operator=(
        const Struct1& obj //!< The source object
    );

    //! Copy assignment operator (raw array)
    Struct1& operator=(
        const ElementType (&a)[SIZE] //!< The source array
    );

    //! Copy assignment operator (single element)
    Struct1& operator=(
        const ElementType& e //!< The element
    );

    //! Equality operator
    bool operator==(
        const Struct1& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const Struct1& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Struct1& obj //!< The object
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Public member functions
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    );

#if FW_SERIALIZABLE_TO_STRING

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

#endif
