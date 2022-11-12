// ======================================================================
// \title  StringPortAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for String port
// ======================================================================

#ifndef StringPortAc_HPP
#define StringPortAc_HPP

#include "FpConfig.hpp"
#include "Fw/Comp/PassiveComponentBase.hpp"
#include "Fw/Port/InputPortBase.hpp"
#include "Fw/Port/OutputPortBase.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/StringType.hpp"
#include "cstdio"
#include "cstring"

// ----------------------------------------------------------------------
// str80String class
// ----------------------------------------------------------------------

class str80String :
  public Fw::StringBase
{

  public:

    enum {
      //! The size of the string length plus the size of the string buffer
      SERIALIZED_SIZE = sizeof(FwBuffSizeType) + 80
    };

    //! Default constructor
    str80String();

    //! Char array constructor
    str80String(const char* src);

    //! String base constructor
    str80String(const Fw::StringBase& src);

    //! Copy constructor
    str80String(const str80String& src);

    //! Destructor
    ~str80String();

    //! Copy assignment operator
    str80String& operator=(const str80String& other);

    //! String base assignment operator
    str80String& operator=(const Fw::StringBase& other);

    //! char* assignment operator
    str80String& operator=(const char* other);

    //! Retrieves char buffer of string
    const char* toChar() const;

    NATIVE_UINT_TYPE getCapacity() const;

  private:

    char m_buf[80]; //!< Buffer for string storage

};

// ----------------------------------------------------------------------
// str100String class
// ----------------------------------------------------------------------

class str100String :
  public Fw::StringBase
{

  public:

    enum {
      //! The size of the string length plus the size of the string buffer
      SERIALIZED_SIZE = sizeof(FwBuffSizeType) + 100
    };

    //! Default constructor
    str100String();

    //! Char array constructor
    str100String(const char* src);

    //! String base constructor
    str100String(const Fw::StringBase& src);

    //! Copy constructor
    str100String(const str100String& src);

    //! Destructor
    ~str100String();

    //! Copy assignment operator
    str100String& operator=(const str100String& other);

    //! String base assignment operator
    str100String& operator=(const Fw::StringBase& other);

    //! char* assignment operator
    str100String& operator=(const char* other);

    //! Retrieves char buffer of string
    const char* toChar() const;

    NATIVE_UINT_TYPE getCapacity() const;

  private:

    char m_buf[100]; //!< Buffer for string storage

};


// ----------------------------------------------------------------------
// String types for backwards compatibility
// ----------------------------------------------------------------------

typedef str80String str80RefString;
typedef str100String str100RefString;

//! Input String port
//! A port with string parameters of duplicate sizes
class InputStringPort :
  public Fw::InputPortBase
{

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representations of the port arguments
      SERIALIZED_SIZE =
        str80String::SERIALIZED_SIZE +
        str80String::SERIALIZED_SIZE +
        str100String::SERIALIZED_SIZE +
        str100String::SERIALIZED_SIZE
    };

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The port callback function type
    typedef void (*CompFuncPtr)(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      const str80String& str80,
      str80String& str80Ref,
      const str100String& str100,
      str100String& str100Ref
    );

  public:

    // ----------------------------------------------------------------------
    // Input Port Member functions
    // ----------------------------------------------------------------------

    //! Constructor
    InputStringPort();

    //! Initialization function
    void init();

    //! Register a component
    void addCallComp(
        Fw::PassiveComponentBase* callComp, //!< The containing component
        CompFuncPtr funcPtr //!< The port callback function
    );

    //! Invoke a port interface
    void invoke(
        const str80String& str80, //!< A string of size 80
        str80String& str80Ref,
        const str100String& str100, //!< A string of size 100
        str100String& str100Ref
    );

  private:

#if FW_PORT_SERIALIZATION == 1

    //! Invoke the port with serialized arguments
    Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase& _buffer);

#endif

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The pointer to the port callback function
    CompFuncPtr m_func;

};

//! Output String port
//! A port with string parameters of duplicate sizes
class OutputStringPort :
  public Fw::OutputPortBase
{

  public:

    // ----------------------------------------------------------------------
    // Output Port Member functions
    // ----------------------------------------------------------------------

    //! Constructor
    OutputStringPort();

    //! Initialization function
    void init();

    //! Register an input port
    void addCallPort(
        InputStringPort* callPort //!< The input port
    );

    //! Invoke a port interface
    void invoke(
        const str80String& str80, //!< A string of size 80
        str80String& str80Ref,
        const str100String& str100, //!< A string of size 100
        str100String& str100Ref
    );

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The pointer to the input port
    InputStringPort* m_port;

};

#endif
