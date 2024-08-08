// ======================================================================
// \title  ActiveOverflowComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for ActiveOverflow component base class
// ======================================================================

#ifndef ActiveOverflowComponentAc_HPP
#define ActiveOverflowComponentAc_HPP

#include "FpConfig.hpp"
#include "Fw/Cmd/CmdPortAc.hpp"
#include "Fw/Cmd/CmdRegPortAc.hpp"
#include "Fw/Cmd/CmdResponsePortAc.hpp"
#include "Fw/Cmd/CmdString.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Dp/DpResponsePortAc.hpp"
#include "Fw/Log/LogPortAc.hpp"
#if FW_ENABLE_TEXT_LOGGING == 1
#include "Fw/Log/LogTextPortAc.hpp"
#endif
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"
#include "Fw/Prm/PrmGetPortAc.hpp"
#include "Fw/Prm/PrmSetPortAc.hpp"
#include "Fw/Time/TimePortAc.hpp"
#include "Fw/Tlm/TlmPortAc.hpp"
#include "Fw/Types/InternalInterfaceString.hpp"
#include "TypedPortAc.hpp"

static_assert(
  FW_PORT_SERIALIZATION == 1,
  "ActiveOverflow component requires serialization"
);

//! \class ActiveOverflowComponentBase
//! \brief Auto-generated base for ActiveOverflow component
//!
//! An active component with overflow behavior
class ActiveOverflowComponentBase :
  public Fw::ActiveComponentBase
{

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    friend class ActiveOverflowComponentBaseFriend;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    //! Enumerations for numbers of special input ports
    enum {
      NUM_CMDIN_INPUT_PORTS = 1,
      NUM_PRODUCTRECVINHOOK_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of typed input ports
    enum {
      NUM_ASSERTASYNC_INPUT_PORTS = 1,
      NUM_BLOCKASYNC_INPUT_PORTS = 1,
      NUM_DROPASYNC_INPUT_PORTS = 1,
      NUM_HOOKASYNC_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of serial input ports
    enum {
      NUM_SERIALASYNCHOOK_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of special output ports
    enum {
      NUM_CMDREGOUT_OUTPUT_PORTS = 1,
      NUM_CMDRESPONSEOUT_OUTPUT_PORTS = 1,
      NUM_EVENTOUT_OUTPUT_PORTS = 1,
      NUM_PRMGETOUT_OUTPUT_PORTS = 1,
      NUM_PRMSETOUT_OUTPUT_PORTS = 1,
      NUM_TEXTEVENTOUT_OUTPUT_PORTS = 1,
      NUM_TIMEGETOUT_OUTPUT_PORTS = 1,
      NUM_TLMOUT_OUTPUT_PORTS = 1,
    };

    //! Command opcodes
    enum {
      OPCODE_CMD_HOOK = 0x0, //!< A command with queue full 'hook' behavior
      OPCODE_CMD_PARAMS_PRIORITY_HOOK = 0x1, //!< A command with params, priority, and queue full 'hook' behavior
    };

  public:

    // ----------------------------------------------------------------------
    // Component initialization
    // ----------------------------------------------------------------------

    //! Initialize ActiveOverflowComponentBase object
    void init(
        FwQueueSizeType queueDepth, //!< The queue depth
        FwSizeType msgSize, //!< The message size
        FwEnumStoreType instance = 0 //!< The instance number
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for special input ports
    // ----------------------------------------------------------------------

    //! Get special input port at index
    //!
    //! \return cmdIn[portNum]
    Fw::InputCmdPort* get_cmdIn_InputPort(
        FwIndexType portNum //!< The port number
    );

    //! Get special input port at index
    //!
    //! \return productRecvInHook[portNum]
    Fw::InputDpResponsePort* get_productRecvInHook_InputPort(
        FwIndexType portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get typed input port at index
    //!
    //! \return assertAsync[portNum]
    Ports::InputTypedPort* get_assertAsync_InputPort(
        FwIndexType portNum //!< The port number
    );

    //! Get typed input port at index
    //!
    //! \return blockAsync[portNum]
    Ports::InputTypedPort* get_blockAsync_InputPort(
        FwIndexType portNum //!< The port number
    );

    //! Get typed input port at index
    //!
    //! \return dropAsync[portNum]
    Ports::InputTypedPort* get_dropAsync_InputPort(
        FwIndexType portNum //!< The port number
    );

    //! Get typed input port at index
    //!
    //! \return hookAsync[portNum]
    Ports::InputTypedPort* get_hookAsync_InputPort(
        FwIndexType portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for serial input ports
    // ----------------------------------------------------------------------

    //! Get serial input port at index
    //!
    //! \return serialAsyncHook[portNum]
    Fw::InputSerializePort* get_serialAsyncHook_InputPort(
        FwIndexType portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Connect input ports to special output ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdRegOut[portNum]
    void set_cmdRegOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputCmdRegPort* port //!< The input port
    );

    //! Connect port to cmdResponseOut[portNum]
    void set_cmdResponseOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputCmdResponsePort* port //!< The input port
    );

    //! Connect port to eventOut[portNum]
    void set_eventOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputLogPort* port //!< The input port
    );

    //! Connect port to prmGetOut[portNum]
    void set_prmGetOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputPrmGetPort* port //!< The input port
    );

    //! Connect port to prmSetOut[portNum]
    void set_prmSetOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputPrmSetPort* port //!< The input port
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Connect port to textEventOut[portNum]
    void set_textEventOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputLogTextPort* port //!< The input port
    );

#endif

    //! Connect port to timeGetOut[portNum]
    void set_timeGetOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputTimePort* port //!< The input port
    );

    //! Connect port to tlmOut[portNum]
    void set_tlmOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputTlmPort* port //!< The input port
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serial input ports to special output ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdRegOut[portNum]
    void set_cmdRegOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to cmdResponseOut[portNum]
    void set_cmdResponseOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to eventOut[portNum]
    void set_eventOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to prmSetOut[portNum]
    void set_prmSetOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Connect port to textEventOut[portNum]
    void set_textEventOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#endif

    //! Connect port to timeGetOut[portNum]
    void set_timeGetOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

    //! Connect port to tlmOut[portNum]
    void set_tlmOut_OutputPort(
        FwIndexType portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Command registration
    // ----------------------------------------------------------------------

    //! \brief Register commands with the Command Dispatcher
    //!
    //! Connect the dispatcher first
    void regCommands();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct ActiveOverflowComponentBase object
    ActiveOverflowComponentBase(
        const char* compName = "" //!< The component name
    );

    //! Destroy ActiveOverflowComponentBase object
    virtual ~ActiveOverflowComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of special input ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdIn input ports
    //!
    //! \return The number of cmdIn input ports
    FwIndexType getNum_cmdIn_InputPorts() const;

    //! Get the number of productRecvInHook input ports
    //!
    //! \return The number of productRecvInHook input ports
    FwIndexType getNum_productRecvInHook_InputPorts() const;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of typed input ports
    // ----------------------------------------------------------------------

    //! Get the number of assertAsync input ports
    //!
    //! \return The number of assertAsync input ports
    FwIndexType getNum_assertAsync_InputPorts() const;

    //! Get the number of blockAsync input ports
    //!
    //! \return The number of blockAsync input ports
    FwIndexType getNum_blockAsync_InputPorts() const;

    //! Get the number of dropAsync input ports
    //!
    //! \return The number of dropAsync input ports
    FwIndexType getNum_dropAsync_InputPorts() const;

    //! Get the number of hookAsync input ports
    //!
    //! \return The number of hookAsync input ports
    FwIndexType getNum_hookAsync_InputPorts() const;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of serial input ports
    // ----------------------------------------------------------------------

    //! Get the number of serialAsyncHook input ports
    //!
    //! \return The number of serialAsyncHook input ports
    FwIndexType getNum_serialAsyncHook_InputPorts() const;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of special output ports
    // ----------------------------------------------------------------------

    //! Get the number of cmdRegOut output ports
    //!
    //! \return The number of cmdRegOut output ports
    FwIndexType getNum_cmdRegOut_OutputPorts() const;

    //! Get the number of cmdResponseOut output ports
    //!
    //! \return The number of cmdResponseOut output ports
    FwIndexType getNum_cmdResponseOut_OutputPorts() const;

    //! Get the number of eventOut output ports
    //!
    //! \return The number of eventOut output ports
    FwIndexType getNum_eventOut_OutputPorts() const;

    //! Get the number of prmGetOut output ports
    //!
    //! \return The number of prmGetOut output ports
    FwIndexType getNum_prmGetOut_OutputPorts() const;

    //! Get the number of prmSetOut output ports
    //!
    //! \return The number of prmSetOut output ports
    FwIndexType getNum_prmSetOut_OutputPorts() const;

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Get the number of textEventOut output ports
    //!
    //! \return The number of textEventOut output ports
    FwIndexType getNum_textEventOut_OutputPorts() const;

#endif

    //! Get the number of timeGetOut output ports
    //!
    //! \return The number of timeGetOut output ports
    FwIndexType getNum_timeGetOut_OutputPorts() const;

    //! Get the number of tlmOut output ports
    //!
    //! \return The number of tlmOut output ports
    FwIndexType getNum_tlmOut_OutputPorts() const;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for special output ports
    // ----------------------------------------------------------------------

    //! Check whether port cmdRegOut is connected
    //!
    //! \return Whether port cmdRegOut is connected
    bool isConnected_cmdRegOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

    //! Check whether port cmdResponseOut is connected
    //!
    //! \return Whether port cmdResponseOut is connected
    bool isConnected_cmdResponseOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

    //! Check whether port eventOut is connected
    //!
    //! \return Whether port eventOut is connected
    bool isConnected_eventOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

    //! Check whether port prmGetOut is connected
    //!
    //! \return Whether port prmGetOut is connected
    bool isConnected_prmGetOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

    //! Check whether port prmSetOut is connected
    //!
    //! \return Whether port prmSetOut is connected
    bool isConnected_prmSetOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Check whether port textEventOut is connected
    //!
    //! \return Whether port textEventOut is connected
    bool isConnected_textEventOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

#endif

    //! Check whether port timeGetOut is connected
    //!
    //! \return Whether port timeGetOut is connected
    bool isConnected_timeGetOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

    //! Check whether port tlmOut is connected
    //!
    //! \return Whether port tlmOut is connected
    bool isConnected_tlmOut_OutputPort(
        FwIndexType portNum //!< The port number
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for special input ports
    //
    // Call these functions directly to bypass the corresponding ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port productRecvInHook
    void productRecvInHook_handlerBase(
        FwIndexType portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The status
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port assertAsync
    virtual void assertAsync_handler(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

    //! Handler for input port blockAsync
    virtual void blockAsync_handler(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

    //! Handler for input port dropAsync
    virtual void dropAsync_handler(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

    //! Handler for input port hookAsync
    virtual void hookAsync_handler(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports
    //
    // Call these functions directly to bypass the corresponding ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port assertAsync
    void assertAsync_handlerBase(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler base-class function for input port blockAsync
    void blockAsync_handlerBase(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler base-class function for input port dropAsync
    void dropAsync_handlerBase(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler base-class function for input port hookAsync
    void hookAsync_handlerBase(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for serial input ports
    // ----------------------------------------------------------------------

    //! Handler for input port serialAsyncHook
    virtual void serialAsyncHook_handler(
        FwIndexType portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for serial input ports
    //
    // Call these functions directly to bypass the corresponding ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port serialAsyncHook
    void serialAsyncHook_handlerBase(
        FwIndexType portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for special async input ports
    //
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default, they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port productRecvInHook
    virtual void productRecvInHook_preMsgHook(
        FwIndexType portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The status
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports
    //
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default, they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port assertAsync
    virtual void assertAsync_preMsgHook(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Pre-message hook for async input port blockAsync
    virtual void blockAsync_preMsgHook(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Pre-message hook for async input port dropAsync
    virtual void dropAsync_preMsgHook(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Pre-message hook for async input port hookAsync
    virtual void hookAsync_preMsgHook(
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for serial async input ports
    //
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default, they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port serialAsyncHook
    virtual void serialAsyncHook_preMsgHook(
        FwIndexType portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Internal interface handlers
    // ----------------------------------------------------------------------

    //! Internal interface handler for internalHookDrop
    virtual void internalHookDrop_internalInterfaceHandler() = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Internal interface base-class functions
    // ----------------------------------------------------------------------

    //! Internal interface base-class function for internalHookDrop
    void internalHookDrop_internalInterfaceInvoke();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command response
    // ----------------------------------------------------------------------

    //! Emit command response
    void cmdResponse_out(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdResponse response //!< The command response
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command CMD_HOOK
    //!
    //! A command with queue full 'hook' behavior
    virtual void CMD_HOOK_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    ) = 0;

    //! Handler for command CMD_PARAMS_PRIORITY_HOOK
    //!
    //! A command with params, priority, and queue full 'hook' behavior
    virtual void CMD_PARAMS_PRIORITY_HOOK_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions
    //
    // Call these functions directly to bypass the command input port
    // ----------------------------------------------------------------------

    //! Base-class handler function for command CMD_HOOK
    //!
    //! A command with queue full 'hook' behavior
    void CMD_HOOK_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

    //! Base-class handler function for command CMD_PARAMS_PRIORITY_HOOK
    //!
    //! A command with params, priority, and queue full 'hook' behavior
    void CMD_PARAMS_PRIORITY_HOOK_cmdHandlerBase(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& args //!< The command argument buffer
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands
    //
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for command CMD_HOOK
    virtual void CMD_HOOK_preMsgHook(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

    //! Pre-message hook for command CMD_PARAMS_PRIORITY_HOOK
    virtual void CMD_PARAMS_PRIORITY_HOOK_preMsgHook(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //!  Get the time
    //!
    //! \\return The current time
    Fw::Time getTime();

  PRIVATE:

    // ----------------------------------------------------------------------
    // Message dispatch functions
    // ----------------------------------------------------------------------

    //! Called in the message loop to dispatch a message from the queue
    virtual MsgDispatchStatus doDispatch();

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on special input ports
    // ----------------------------------------------------------------------

    //! Callback for port cmdIn
    static void m_p_cmdIn_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        FwOpcodeType opCode, //!< Command Op Code
        U32 cmdSeq, //!< Command Sequence
        Fw::CmdArgBuffer& args //!< Buffer containing arguments
    );

    //! Callback for port productRecvInHook
    static void m_p_productRecvInHook_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The status
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port assertAsync
    static void m_p_assertAsync_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Callback for port blockAsync
    static void m_p_blockAsync_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Callback for port dropAsync
    static void m_p_dropAsync_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Callback for port hookAsync
    static void m_p_hookAsync_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Fw::StringBase& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on serial input ports
    // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

    //! Callback for port serialAsyncHook
    static void m_p_serialAsyncHook_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        FwIndexType portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

#endif

  PRIVATE:

    // ----------------------------------------------------------------------
    // Private data product handling functions
    // ----------------------------------------------------------------------

    //! Handler implementation for productRecvInHook
    void productRecvInHook_handler(
        const FwIndexType portNum, //!< The port number
        FwDpIdType id, //!< The container id
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The buffer status
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Special input ports
    // ----------------------------------------------------------------------

    //! Input port cmdIn
    Fw::InputCmdPort m_cmdIn_InputPort[NUM_CMDIN_INPUT_PORTS];

    //! Input port productRecvInHook
    Fw::InputDpResponsePort m_productRecvInHook_InputPort[NUM_PRODUCTRECVINHOOK_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port assertAsync
    Ports::InputTypedPort m_assertAsync_InputPort[NUM_ASSERTASYNC_INPUT_PORTS];

    //! Input port blockAsync
    Ports::InputTypedPort m_blockAsync_InputPort[NUM_BLOCKASYNC_INPUT_PORTS];

    //! Input port dropAsync
    Ports::InputTypedPort m_dropAsync_InputPort[NUM_DROPASYNC_INPUT_PORTS];

    //! Input port hookAsync
    Ports::InputTypedPort m_hookAsync_InputPort[NUM_HOOKASYNC_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Serial input ports
    // ----------------------------------------------------------------------

    //! Input port serialAsyncHook
    Fw::InputSerializePort m_serialAsyncHook_InputPort[NUM_SERIALASYNCHOOK_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Special output ports
    // ----------------------------------------------------------------------

    //! Output port cmdRegOut
    Fw::OutputCmdRegPort m_cmdRegOut_OutputPort[NUM_CMDREGOUT_OUTPUT_PORTS];

    //! Output port cmdResponseOut
    Fw::OutputCmdResponsePort m_cmdResponseOut_OutputPort[NUM_CMDRESPONSEOUT_OUTPUT_PORTS];

    //! Output port eventOut
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

    //! Output port prmGetOut
    Fw::OutputPrmGetPort m_prmGetOut_OutputPort[NUM_PRMGETOUT_OUTPUT_PORTS];

    //! Output port prmSetOut
    Fw::OutputPrmSetPort m_prmSetOut_OutputPort[NUM_PRMSETOUT_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Output port textEventOut
    Fw::OutputLogTextPort m_textEventOut_OutputPort[NUM_TEXTEVENTOUT_OUTPUT_PORTS];

#endif

    //! Output port timeGetOut
    Fw::OutputTimePort m_timeGetOut_OutputPort[NUM_TIMEGETOUT_OUTPUT_PORTS];

    //! Output port tlmOut
    Fw::OutputTlmPort m_tlmOut_OutputPort[NUM_TLMOUT_OUTPUT_PORTS];

  PRIVATE:

    //! Stores max message size
    FwSizeType m_msgSize;

};

#endif
