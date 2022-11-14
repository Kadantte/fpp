// ======================================================================
// \title  ReturnTypePortAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ReturnType port
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "ReturnTypePortAc.hpp"

namespace M {

  // ----------------------------------------------------------------------
  // Input Port Member functions
  // ----------------------------------------------------------------------

  InputReturnTypePort ::
    InputReturnTypePort() :
      Fw::InputPortBase(),
      m_func(nullptr)
  {

  }

  void InputReturnTypePort ::
    init()
  {
    Fw::InputPortBase::init();
  }

  void InputReturnTypePort ::
    addCallComp(
        Fw::PassiveComponentBase* callComp,
        CompFuncPtr funcPtr
    )
  {
    FW_ASSERT(callComp);
    FW_ASSERT(funcPtr);

    this->m_comp = callComp;
    this->m_func = funcPtr;
    this->m_connObj = callComp;
  }

  U32 InputReturnTypePort ::
    invoke(U32 u)
  {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

    FW_ASSERT(this->m_comp);
    FW_ASSERT(this->m_func);

    return this->m_func(this->m_comp, this->m_portNum, u);
  }

#if FW_PORT_SERIALIZATION == 1

  Fw::SerializeStatus InputReturnTypePort ::
    invokeSerial(Fw::SerializeBufferBase& _buffer)
  {
    // For ports with a return type, invokeSerial is not used
    (void) _buffer;

    FW_ASSERT(0);
    return Fw::FW_SERIALIZE_OK;
  }

#endif

  // ----------------------------------------------------------------------
  // Output Port Member functions
  // ----------------------------------------------------------------------

  OutputReturnTypePort ::
    OutputReturnTypePort() :
      Fw::OutputPortBase(),
      m_port(nullptr)
  {

  }

  void OutputReturnTypePort ::
    init()
  {
    Fw::OutputPortBase::init();
  }

  void OutputReturnTypePort ::
    addCallPort(InputReturnTypePort* callPort)
  {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;

#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
  }

  U32 OutputReturnTypePort ::
    invoke(U32 u)
  {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port || this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif
    return this->m_port->invoke(u);
  }

}
