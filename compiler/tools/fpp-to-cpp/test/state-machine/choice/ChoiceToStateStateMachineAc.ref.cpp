// ======================================================================
// \title  ChoiceToStateStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ChoiceToState state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "state-machine/choice/ChoiceToStateStateMachineAc.hpp"

namespace FppTest {

  namespace SmChoice {

    // ----------------------------------------------------------------------
    // Constructors and Destructors
    // ----------------------------------------------------------------------

    ChoiceToStateStateMachineBase ::
      ChoiceToStateStateMachineBase()
    {

    }

    ChoiceToStateStateMachineBase ::
      ~ChoiceToStateStateMachineBase()
    {

    }

    // ----------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------

    void ChoiceToStateStateMachineBase ::
      initBase(const FwEnumStoreType id)
    {
      this->m_id = id;
      // Enter the initial target of the state machine
      this->enter_S1(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    }

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    ChoiceToStateStateMachineBase::State ChoiceToStateStateMachineBase ::
      getState() const
    {
      return this->m_state;
    }

    // ----------------------------------------------------------------------
    // Send signal functions
    // ----------------------------------------------------------------------

    void ChoiceToStateStateMachineBase ::
      sendSignal_s()
    {
      switch (this->m_state) {
        case State::S1:
          // Enter the target
          this->enter_S1_C(Signal::s);
          break;
        case State::S2_S3:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    // ----------------------------------------------------------------------
    // State and choice entry
    // ----------------------------------------------------------------------

    void ChoiceToStateStateMachineBase ::
      enter_S2(Signal signal)
    {
      // Do the entry actions
      this->action_enterS2(signal);
      // Do the actions for the initial transition
      this->action_a(signal);
      // Enter the target of the initial transition
      this->enter_S2_S3(signal);
    }

    void ChoiceToStateStateMachineBase ::
      enter_S2_S3(Signal signal)
    {
      // Do the entry actions
      this->action_enterS3(signal);
      // Update the state
      this->m_state = State::S2_S3;
    }

    void ChoiceToStateStateMachineBase ::
      enter_S1(Signal signal)
    {
      // Update the state
      this->m_state = State::S1;
    }

    void ChoiceToStateStateMachineBase ::
      enter_S1_C(Signal signal)
    {
      if (this->guard_g(signal)) {
        // Do the actions for the transition
        this->action_exitS1(signal);
        this->action_a(signal);
        // Enter the target
        this->enter_S2(signal);
      }
      else {
        // Do the actions for the transition
        this->action_exitS1(signal);
        this->action_a(signal);
        this->action_enterS2(signal);
        // Enter the target
        this->enter_S2_S3(signal);
      }
    }

  }

}
