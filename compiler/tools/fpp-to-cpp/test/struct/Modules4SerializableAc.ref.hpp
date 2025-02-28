// ======================================================================
// \title  Modules4SerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Modules4 struct
// ======================================================================

#ifndef Modules4SerializableAc_HPP
#define Modules4SerializableAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/ExternalString.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"
#include "Modules2SerializableAc.hpp"

class Modules4 :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The type of arr1
    using Type_of_arr1 = M::Modules2[3];

    //! The type of arr2
    using Type_of_arr2 = M::Modules2[6];

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        M::Modules2::SERIALIZED_SIZE * 3 +
        M::Modules2::SERIALIZED_SIZE * 6
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    Modules4();

    //! Member constructor
    Modules4(
        const Type_of_arr1& arr1,
        const Type_of_arr2& arr2
    );

    //! Copy constructor
    Modules4(
        const Modules4& obj //!< The source object
    );

    //! Member constructor (scalar values for arrays)
    Modules4(
        const M::Modules2& arr1,
        const M::Modules2& arr2
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    Modules4& operator=(
        const Modules4& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const Modules4& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const Modules4& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Modules4& obj //!< The object
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

#if FW_SERIALIZABLE_TO_STRING

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member arr1
    Type_of_arr1& getarr1()
    {
      return this->m_arr1;
    }

    //! Get member arr1 (const)
    const Type_of_arr1& getarr1() const
    {
      return this->m_arr1;
    }

    //! Get member arr2
    Type_of_arr2& getarr2()
    {
      return this->m_arr2;
    }

    //! Get member arr2 (const)
    const Type_of_arr2& getarr2() const
    {
      return this->m_arr2;
    }

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(
        const Type_of_arr1& arr1,
        const Type_of_arr2& arr2
    );

    //! Set member arr1
    void setarr1(const Type_of_arr1& arr1);

    //! Set member arr2
    void setarr2(const Type_of_arr2& arr2);

  protected:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    M::Modules2 m_arr1[3];
    M::Modules2 m_arr2[6];

};

#endif
