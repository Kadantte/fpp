// ======================================================================
// \title  StringArraySerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for StringArray struct
// ======================================================================

#ifndef StringArraySerializableAc_HPP
#define StringArraySerializableAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

class StringArray :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // StringSize80 class
    // ----------------------------------------------------------------------

    class StringSize80 :
      public Fw::StringBase
    {

      public:

        enum {
          SERIALIZED_SIZE = 80 + sizeof(FwBuffSizeType) //!< Size of buffer + storage of two size words
        };

        //! Default constructor
        StringSize80();

        //! Char array constructor
        StringSize80(const char* src);

        //! String base constructor
        StringSize80(const Fw::StringBase& src);

        //! Copy constructor
        StringSize80(const StringSize80& src);

        //! Destructor
        ~StringSize80();

        //! Copy assignment operator
        StringSize80& operator=(const StringSize80& other);

        //! String base assignment operator
        StringSize80& operator=(const Fw::StringBase& other);

        //! char* assignment operator
        StringSize80& operator=(const char* other);

        //! Retrieves char buffer of string
        const char* toChar() const;

        NATIVE_UINT_TYPE getCapacity() const;

      private:

        char m_buf[80]; //!< Buffer for string storage

    };

    // ----------------------------------------------------------------------
    // StringSize40 class
    // ----------------------------------------------------------------------

    class StringSize40 :
      public Fw::StringBase
    {

      public:

        enum {
          SERIALIZED_SIZE = 40 + sizeof(FwBuffSizeType) //!< Size of buffer + storage of two size words
        };

        //! Default constructor
        StringSize40();

        //! Char array constructor
        StringSize40(const char* src);

        //! String base constructor
        StringSize40(const Fw::StringBase& src);

        //! Copy constructor
        StringSize40(const StringSize40& src);

        //! Destructor
        ~StringSize40();

        //! Copy assignment operator
        StringSize40& operator=(const StringSize40& other);

        //! String base assignment operator
        StringSize40& operator=(const Fw::StringBase& other);

        //! char* assignment operator
        StringSize40& operator=(const char* other);

        //! Retrieves char buffer of string
        const char* toChar() const;

        NATIVE_UINT_TYPE getCapacity() const;

      private:

        char m_buf[40]; //!< Buffer for string storage

    };

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The array member types
    typedef StringSize40 Type_of_s2[16];

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        StringSize80::SERIALIZED_SIZE +
        StringSize40::SERIALIZED_SIZE * 16
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    StringArray();

    //! Member constructor
    StringArray(
        const StringSize80& s1,
        const Type_of_s2& s2
    );

    //! Copy constructor
    StringArray(
        const StringArray& obj //!< The source object
    );

    //! Member constructor (scalar values for arrays)
    StringArray(
        const StringSize80& s1,
        const StringSize40& s2
    );

    //! Copy assignment operator
    StringArray& operator=(
        const StringArray& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const StringArray& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const StringArray& obj //!< The other object
    ) const;

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

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const StringArray& obj //!< The object
    );

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member s1
    StringSize80& get_s1();

    //! Get member s1 (const)
    const StringSize80& get_s1() const;

    //! Get member s2
    Type_of_s2& get_s2();

    //! Get member s2 (const)
    const Type_of_s2& get_s2() const;

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(
        const StringSize80& s1,
        const Type_of_s2& s2
    );

    //! Set member s1
    void set_s1(const StringSize80& s1);

    //! Set member s2
    void set_s2(const Type_of_s2& s2);

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    StringSize80 s1;
    StringSize40 s2[16];

};

#endif
