// ======================================================================
// \title  ActiveAsyncProductPortsOnlyTesterBase.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveAsyncProductPortsOnly component test harness base class
// ======================================================================

#include <cstdlib>
#include <cstring>

#include "test-base/ActiveAsyncProductPortsOnlyTesterBase.hpp"

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void ActiveAsyncProductPortsOnlyTesterBase ::
  init(NATIVE_INT_TYPE instance)
{
  // Initialize base class
  Fw::PassiveComponentBase::init(instance);
}

// ----------------------------------------------------------------------
// Connectors for to ports
// ----------------------------------------------------------------------

void ActiveAsyncProductPortsOnlyTesterBase ::
  connect_to_productRecvIn(
      NATIVE_INT_TYPE portNum,
      Fw::InputDpResponsePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_productRecvIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_productRecvIn[portNum].addCallPort(port);
}

// ----------------------------------------------------------------------
// Getters for from ports
// ----------------------------------------------------------------------

Fw::InputDpRequestPort* ActiveAsyncProductPortsOnlyTesterBase ::
  get_from_productRequestOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productRequestOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productRequestOut[portNum];
}

Fw::InputDpSendPort* ActiveAsyncProductPortsOnlyTesterBase ::
  get_from_productSendOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productSendOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productSendOut[portNum];
}

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ActiveAsyncProductPortsOnlyTesterBase ::
  ActiveAsyncProductPortsOnlyTesterBase(
      const char* const compName,
      const U32 maxHistorySize
  ) :
    Fw::PassiveComponentBase(compName)
{

}

ActiveAsyncProductPortsOnlyTesterBase ::
  ~ActiveAsyncProductPortsOnlyTesterBase()
{

}

// ----------------------------------------------------------------------
// Getters for port counts
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveAsyncProductPortsOnlyTesterBase ::
  getNum_to_productRecvIn() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_productRecvIn));
}

NATIVE_INT_TYPE ActiveAsyncProductPortsOnlyTesterBase ::
  getNum_from_productRequestOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productRequestOut));
}

NATIVE_INT_TYPE ActiveAsyncProductPortsOnlyTesterBase ::
  getNum_from_productSendOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productSendOut));
}

// ----------------------------------------------------------------------
// Connection status queries for to ports
// ----------------------------------------------------------------------

bool ActiveAsyncProductPortsOnlyTesterBase ::
  isConnected_to_productRecvIn(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_productRecvIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_productRecvIn[portNum].isConnected();
}
