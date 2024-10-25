// ======================================================================
// \title  SmInitialQueuedComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for SmInitialQueued component base class
// ======================================================================

#ifndef FppTest_SmInitialQueuedComponentAc_HPP
#define FppTest_SmInitialQueuedComponentAc_HPP

#include "FpConfig.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"
#include "SmInitialQueued_BasicStateMachineAc.hpp"
#include "SmInitialQueued_JunctionStateMachineAc.hpp"
#include "SmInitialQueued_NestedStateMachineAc.hpp"
#include "Svc/Sched/SchedPortAc.hpp"
#include "state-machine/initial/BasicStateMachineAc.hpp"
#include "state-machine/initial/JunctionStateMachineAc.hpp"
#include "state-machine/initial/NestedStateMachineAc.hpp"

namespace FppTest {

  //! \class SmInitialQueuedComponentBase
  //! \brief Auto-generated base for SmInitialQueued component
  class SmInitialQueuedComponentBase :
    public Fw::QueuedComponentBase
  {

      // ----------------------------------------------------------------------
      // Friend classes
      // ----------------------------------------------------------------------

      //! Friend class for white-box testing
      friend class SmInitialQueuedComponentBaseFriend;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      //! Enumerations for numbers of typed input ports
      enum {
        NUM_SCHEDIN_INPUT_PORTS = 1,
      };

      //! State machine identifiers
      enum class SmId : FwEnumStoreType {
        basic,
        junction,
        nested,
        smInitialBasic,
        smInitialJunction,
        smInitialNested,
      };

    PROTECTED:

      // ----------------------------------------------------------------------
      // Types for internal state machines
      // ----------------------------------------------------------------------

      //! Implementation of state machine FppTest_SmInitial_Basic
      class FppTest_SmInitial_Basic :
        public FppTest::SmInitial::BasicStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitial_Basic(
              SmInitialQueuedComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              SmInitialQueuedComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          SmInitialQueuedComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          SmInitialQueuedComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitial_Junction
      class FppTest_SmInitial_Junction :
        public FppTest::SmInitial::JunctionStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitial_Junction(
              SmInitialQueuedComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              SmInitialQueuedComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          SmInitialQueuedComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! Implementation for guard g
          bool guard_g(
              Signal signal //!< The signal
          ) const;

        PRIVATE:

          //! The enclosing component
          SmInitialQueuedComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitial_Nested
      class FppTest_SmInitial_Nested :
        public FppTest::SmInitial::NestedStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitial_Nested(
              SmInitialQueuedComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              SmInitialQueuedComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          SmInitialQueuedComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          SmInitialQueuedComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitialQueued_Basic
      class FppTest_SmInitialQueued_Basic :
        public FppTest::SmInitialQueued_BasicStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitialQueued_Basic(
              SmInitialQueuedComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              SmInitialQueuedComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          SmInitialQueuedComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          SmInitialQueuedComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitialQueued_Junction
      class FppTest_SmInitialQueued_Junction :
        public FppTest::SmInitialQueued_JunctionStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitialQueued_Junction(
              SmInitialQueuedComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              SmInitialQueuedComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          SmInitialQueuedComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! Implementation for guard g
          bool guard_g(
              Signal signal //!< The signal
          ) const;

        PRIVATE:

          //! The enclosing component
          SmInitialQueuedComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitialQueued_Nested
      class FppTest_SmInitialQueued_Nested :
        public FppTest::SmInitialQueued_NestedStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitialQueued_Nested(
              SmInitialQueuedComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              SmInitialQueuedComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          SmInitialQueuedComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          SmInitialQueuedComponentBase& m_component;

      };

    public:

      // ----------------------------------------------------------------------
      // Component initialization
      // ----------------------------------------------------------------------

      //! Initialize SmInitialQueuedComponentBase object
      void init(
          FwSizeType queueDepth, //!< The queue depth
          FwEnumStoreType instance = 0 //!< The instance number
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for typed input ports
      // ----------------------------------------------------------------------

      //! Get typed input port at index
      //!
      //! \return schedIn[portNum]
      Svc::InputSchedPort* get_schedIn_InputPort(
          FwIndexType portNum //!< The port number
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct SmInitialQueuedComponentBase object
      SmInitialQueuedComponentBase(
          const char* compName = "" //!< The component name
      );

      //! Destroy SmInitialQueuedComponentBase object
      virtual ~SmInitialQueuedComponentBase();

    PROTECTED:

      // ----------------------------------------------------------------------
      // Getters for numbers of typed input ports
      // ----------------------------------------------------------------------

      //! Get the number of schedIn input ports
      //!
      //! \return The number of schedIn input ports
      FwIndexType getNum_schedIn_InputPorts() const;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Handlers to implement for typed input ports
      // ----------------------------------------------------------------------

      //! Handler for input port schedIn
      virtual void schedIn_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Port handler base-class functions for typed input ports
      //
      // Call these functions directly to bypass the corresponding ports
      // ----------------------------------------------------------------------

      //! Handler base-class function for input port schedIn
      void schedIn_handlerBase(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // State getter functions
      // ----------------------------------------------------------------------

      //! Get the state of state machine instance basic
      FppTest_SmInitialQueued_Basic::State basic_getState() const;

      //! Get the state of state machine instance junction
      FppTest_SmInitialQueued_Junction::State junction_getState() const;

      //! Get the state of state machine instance nested
      FppTest_SmInitialQueued_Nested::State nested_getState() const;

      //! Get the state of state machine instance smInitialBasic
      FppTest_SmInitial_Basic::State smInitialBasic_getState() const;

      //! Get the state of state machine instance smInitialJunction
      FppTest_SmInitial_Junction::State smInitialJunction_getState() const;

      //! Get the state of state machine instance smInitialNested
      FppTest_SmInitial_Nested::State smInitialNested_getState() const;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Overflow hooks for internal state machine instances
      //
      // When sending a signal to a state machine instance, if
      // the queue overflows and the instance is marked with 'hook' behavior,
      // the corresponding function here is called.
      // ----------------------------------------------------------------------

      //! Overflow hook for state machine smInitialNested
      virtual void smInitialNested_stateMachineOverflowHook(
          SmId smId, //!< The state machine ID
          FwEnumStoreType signal, //!< The signal
          Fw::SerializeBufferBase& buffer //!< The message buffer
      ) = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Functions to implement for internal state machine actions
      // ----------------------------------------------------------------------

      //! Implementation for action a of state machine FppTest_SmInitial_Basic
      //!
      //! Action a
      virtual void FppTest_SmInitial_Basic_action_a(
          SmId smId, //!< The state machine id
          FppTest_SmInitial_Basic::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_SmInitial_Junction
      //!
      //! Action a
      virtual void FppTest_SmInitial_Junction_action_a(
          SmId smId, //!< The state machine id
          FppTest_SmInitial_Junction::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_SmInitial_Nested
      //!
      //! Action a
      virtual void FppTest_SmInitial_Nested_action_a(
          SmId smId, //!< The state machine id
          FppTest_SmInitial_Nested::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_SmInitialQueued_Basic
      //!
      //! Action a
      virtual void FppTest_SmInitialQueued_Basic_action_a(
          SmId smId, //!< The state machine id
          FppTest_SmInitialQueued_Basic::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_SmInitialQueued_Junction
      //!
      //! Action a
      virtual void FppTest_SmInitialQueued_Junction_action_a(
          SmId smId, //!< The state machine id
          FppTest_SmInitialQueued_Junction::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_SmInitialQueued_Nested
      //!
      //! Action a
      virtual void FppTest_SmInitialQueued_Nested_action_a(
          SmId smId, //!< The state machine id
          FppTest_SmInitialQueued_Nested::Signal signal //!< The signal
      ) = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Functions to implement for internal state machine guards
      // ----------------------------------------------------------------------

      //! Implementation for guard g of state machine FppTest_SmInitial_Junction
      //!
      //! Guard g
      virtual bool FppTest_SmInitial_Junction_guard_g(
          SmId smId, //!< The state machine id
          FppTest_SmInitial_Junction::Signal signal //!< The signal
      ) const = 0;

      //! Implementation for guard g of state machine FppTest_SmInitialQueued_Junction
      //!
      //! Guard g
      virtual bool FppTest_SmInitialQueued_Junction_guard_g(
          SmId smId, //!< The state machine id
          FppTest_SmInitialQueued_Junction::Signal signal //!< The signal
      ) const = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Message dispatch functions
      // ----------------------------------------------------------------------

      //! Called in the message loop to dispatch a message from the queue
      virtual MsgDispatchStatus doDispatch();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Calls for messages received on typed input ports
      // ----------------------------------------------------------------------

      //! Callback for port schedIn
      static void m_p_schedIn_in(
          Fw::PassiveComponentBase* callComp, //!< The component instance
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Helper functions for state machine dispatch
      // ----------------------------------------------------------------------

      //! Dispatch a signal to a state machine instance
      void smDispatch(
          Fw::SerializeBufferBase& buffer //!< The message buffer
      );

      //! Deserialize the state machine ID and signal from the message buffer
      static void deserializeSmIdAndSignal(
          Fw::SerializeBufferBase& buffer, //!< The message buffer (input and output)
          FwEnumStoreType& smId, //!< The state machine ID (output)
          FwEnumStoreType& signal //!< The signal (output)
      );

      //! Dispatch a signal to a state machine instance of type FppTest_SmInitial_Basic
      void FppTest_SmInitial_Basic_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_SmInitial_Basic& sm, //!< The state machine
          FppTest_SmInitial_Basic::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_SmInitial_Junction
      void FppTest_SmInitial_Junction_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_SmInitial_Junction& sm, //!< The state machine
          FppTest_SmInitial_Junction::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_SmInitial_Nested
      void FppTest_SmInitial_Nested_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_SmInitial_Nested& sm, //!< The state machine
          FppTest_SmInitial_Nested::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_SmInitialQueued_Basic
      void FppTest_SmInitialQueued_Basic_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_SmInitialQueued_Basic& sm, //!< The state machine
          FppTest_SmInitialQueued_Basic::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_SmInitialQueued_Junction
      void FppTest_SmInitialQueued_Junction_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_SmInitialQueued_Junction& sm, //!< The state machine
          FppTest_SmInitialQueued_Junction::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_SmInitialQueued_Nested
      void FppTest_SmInitialQueued_Nested_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_SmInitialQueued_Nested& sm, //!< The state machine
          FppTest_SmInitialQueued_Nested::Signal signal //!< The signal
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Typed input ports
      // ----------------------------------------------------------------------

      //! Input port schedIn
      Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

    PRIVATE:

      // ----------------------------------------------------------------------
      // State machine instances
      // ----------------------------------------------------------------------

      //! State machine basic
      FppTest_SmInitialQueued_Basic m_stateMachine_basic;

      //! State machine junction
      FppTest_SmInitialQueued_Junction m_stateMachine_junction;

      //! State machine nested
      FppTest_SmInitialQueued_Nested m_stateMachine_nested;

      //! State machine smInitialBasic
      FppTest_SmInitial_Basic m_stateMachine_smInitialBasic;

      //! State machine smInitialJunction
      FppTest_SmInitial_Junction m_stateMachine_smInitialJunction;

      //! State machine smInitialNested
      FppTest_SmInitial_Nested m_stateMachine_smInitialNested;

  };

}

#endif
