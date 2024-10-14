// ======================================================================
// \title  ActiveSmInitialComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for ActiveSmInitial component base class
// ======================================================================

#ifndef FppTest_ActiveSmInitialComponentAc_HPP
#define FppTest_ActiveSmInitialComponentAc_HPP

#include "ActiveSmInitial_BasicStateMachineAc.hpp"
#include "ActiveSmInitial_JunctionStateMachineAc.hpp"
#include "ActiveSmInitial_NestedStateMachineAc.hpp"
#include "FpConfig.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"
#include "state-machine/initial/BasicStateMachineAc.hpp"
#include "state-machine/initial/JunctionStateMachineAc.hpp"
#include "state-machine/initial/NestedStateMachineAc.hpp"

namespace FppTest {

  //! \class ActiveSmInitialComponentBase
  //! \brief Auto-generated base for ActiveSmInitial component
  class ActiveSmInitialComponentBase :
    public Fw::ActiveComponentBase
  {

      // ----------------------------------------------------------------------
      // Friend classes
      // ----------------------------------------------------------------------

      //! Friend class for white-box testing
      friend class ActiveSmInitialComponentBaseFriend;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

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

      //! Implementation of state machine FppTest_ActiveSmInitial_Basic
      class FppTest_ActiveSmInitial_Basic :
        public FppTest::ActiveSmInitial_BasicStateMachineBase
      {

        public:

          //! Constructor
          FppTest_ActiveSmInitial_Basic(
              ActiveSmInitialComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              ActiveSmInitialComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          ActiveSmInitialComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          ActiveSmInitialComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_ActiveSmInitial_Junction
      class FppTest_ActiveSmInitial_Junction :
        public FppTest::ActiveSmInitial_JunctionStateMachineBase
      {

        public:

          //! Constructor
          FppTest_ActiveSmInitial_Junction(
              ActiveSmInitialComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              ActiveSmInitialComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          ActiveSmInitialComponentBase::SmId getId() const;

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
          ActiveSmInitialComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_ActiveSmInitial_Nested
      class FppTest_ActiveSmInitial_Nested :
        public FppTest::ActiveSmInitial_NestedStateMachineBase
      {

        public:

          //! Constructor
          FppTest_ActiveSmInitial_Nested(
              ActiveSmInitialComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              ActiveSmInitialComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          ActiveSmInitialComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          ActiveSmInitialComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitial_Basic
      class FppTest_SmInitial_Basic :
        public FppTest::SmInitial::BasicStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitial_Basic(
              ActiveSmInitialComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              ActiveSmInitialComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          ActiveSmInitialComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          ActiveSmInitialComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitial_Junction
      class FppTest_SmInitial_Junction :
        public FppTest::SmInitial::JunctionStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitial_Junction(
              ActiveSmInitialComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              ActiveSmInitialComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          ActiveSmInitialComponentBase::SmId getId() const;

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
          ActiveSmInitialComponentBase& m_component;

      };

      //! Implementation of state machine FppTest_SmInitial_Nested
      class FppTest_SmInitial_Nested :
        public FppTest::SmInitial::NestedStateMachineBase
      {

        public:

          //! Constructor
          FppTest_SmInitial_Nested(
              ActiveSmInitialComponentBase& component //!< The enclosing component
          );

        public:

          //! Initialize the state machine
          void init(
              ActiveSmInitialComponentBase::SmId smId //!< The state machine id
          );

        public:

          //! Get the state machine id
          ActiveSmInitialComponentBase::SmId getId() const;

        PRIVATE:

          //! Implementation for action a
          void action_a(
              Signal signal //!< The signal
          );

        PRIVATE:

          //! The enclosing component
          ActiveSmInitialComponentBase& m_component;

      };

    public:

      // ----------------------------------------------------------------------
      // Component initialization
      // ----------------------------------------------------------------------

      //! Initialize ActiveSmInitialComponentBase object
      void init(
          FwSizeType queueDepth, //!< The queue depth
          FwEnumStoreType instance = 0 //!< The instance number
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct ActiveSmInitialComponentBase object
      ActiveSmInitialComponentBase(
          const char* compName = "" //!< The component name
      );

      //! Destroy ActiveSmInitialComponentBase object
      virtual ~ActiveSmInitialComponentBase();

    PROTECTED:

      // ----------------------------------------------------------------------
      // State getter functions
      // ----------------------------------------------------------------------

      //! Get the state of state machine instance basic
      FppTest_ActiveSmInitial_Basic::State basic_getState() const;

      //! Get the state of state machine instance junction
      FppTest_ActiveSmInitial_Junction::State junction_getState() const;

      //! Get the state of state machine instance nested
      FppTest_ActiveSmInitial_Nested::State nested_getState() const;

      //! Get the state of state machine instance smInitialBasic
      FppTest_SmInitial_Basic::State smInitialBasic_getState() const;

      //! Get the state of state machine instance smInitialJunction
      FppTest_SmInitial_Junction::State smInitialJunction_getState() const;

      //! Get the state of state machine instance smInitialNested
      FppTest_SmInitial_Nested::State smInitialNested_getState() const;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Functions to implement for internal state machine actions
      // ----------------------------------------------------------------------

      //! Implementation for action a of state machine FppTest_ActiveSmInitial_Basic
      //!
      //! Action a
      virtual void FppTest_ActiveSmInitial_Basic_action_a(
          SmId smId, //!< The state machine id
          FppTest_ActiveSmInitial_Basic::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_ActiveSmInitial_Junction
      //!
      //! Action a
      virtual void FppTest_ActiveSmInitial_Junction_action_a(
          SmId smId, //!< The state machine id
          FppTest_ActiveSmInitial_Junction::Signal signal //!< The signal
      ) = 0;

      //! Implementation for action a of state machine FppTest_ActiveSmInitial_Nested
      //!
      //! Action a
      virtual void FppTest_ActiveSmInitial_Nested_action_a(
          SmId smId, //!< The state machine id
          FppTest_ActiveSmInitial_Nested::Signal signal //!< The signal
      ) = 0;

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

    PROTECTED:

      // ----------------------------------------------------------------------
      // Functions to implement for internal state machine guards
      // ----------------------------------------------------------------------

      //! Implementation for guard g of state machine FppTest_ActiveSmInitial_Junction
      //!
      //! Guard g
      virtual bool FppTest_ActiveSmInitial_Junction_guard_g(
          SmId smId, //!< The state machine id
          FppTest_ActiveSmInitial_Junction::Signal signal //!< The signal
      ) = 0;

      //! Implementation for guard g of state machine FppTest_SmInitial_Junction
      //!
      //! Guard g
      virtual bool FppTest_SmInitial_Junction_guard_g(
          SmId smId, //!< The state machine id
          FppTest_SmInitial_Junction::Signal signal //!< The signal
      ) = 0;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Message dispatch functions
      // ----------------------------------------------------------------------

      //! Called in the message loop to dispatch a message from the queue
      virtual MsgDispatchStatus doDispatch();

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

      //! Dispatch a signal to a state machine instance of type FppTest_ActiveSmInitial_Basic
      void FppTest_ActiveSmInitial_Basic_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_ActiveSmInitial_Basic& sm, //!< The state machine
          FppTest_ActiveSmInitial_Basic::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_ActiveSmInitial_Junction
      void FppTest_ActiveSmInitial_Junction_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_ActiveSmInitial_Junction& sm, //!< The state machine
          FppTest_ActiveSmInitial_Junction::Signal signal //!< The signal
      );

      //! Dispatch a signal to a state machine instance of type FppTest_ActiveSmInitial_Nested
      void FppTest_ActiveSmInitial_Nested_smDispatch(
          Fw::SerializeBufferBase& buffer, //!< The message buffer
          FppTest_ActiveSmInitial_Nested& sm, //!< The state machine
          FppTest_ActiveSmInitial_Nested::Signal signal //!< The signal
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

    PRIVATE:

      // ----------------------------------------------------------------------
      // State machine instances
      // ----------------------------------------------------------------------

      //! State machine basic
      FppTest_ActiveSmInitial_Basic m_stateMachine_basic;

      //! State machine junction
      FppTest_ActiveSmInitial_Junction m_stateMachine_junction;

      //! State machine nested
      FppTest_ActiveSmInitial_Nested m_stateMachine_nested;

      //! State machine smInitialBasic
      FppTest_SmInitial_Basic m_stateMachine_smInitialBasic;

      //! State machine smInitialJunction
      FppTest_SmInitial_Junction m_stateMachine_smInitialJunction;

      //! State machine smInitialNested
      FppTest_SmInitial_Nested m_stateMachine_smInitialNested;

  };

}

#endif
