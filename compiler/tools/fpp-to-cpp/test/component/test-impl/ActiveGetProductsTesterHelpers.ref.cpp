// ======================================================================
// \title  ActiveGetProductsTesterHelpers.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveGetProducts component test harness helper functions
// ======================================================================

#include "ActiveGetProductsTester.hpp"

// ----------------------------------------------------------------------
// Helper functions
// ----------------------------------------------------------------------

void ActiveGetProductsTester ::
  connectPorts()
{
  // Connect special output ports

  this->component.set_productGetOut_OutputPort(
    0,
    this->get_from_productGetOut(0)
  );

  this->component.set_productSendOut_OutputPort(
    0,
    this->get_from_productSendOut(0)
  );

  this->component.set_timeGetOut_OutputPort(
    0,
    this->get_from_timeGetOut(0)
  );

  // Connect typed input ports

  this->connect_to_noArgsAsync(
    0,
    this->component.get_noArgsAsync_InputPort(0)
  );

  this->connect_to_noArgsGuarded(
    0,
    this->component.get_noArgsGuarded_InputPort(0)
  );

  this->connect_to_noArgsReturnGuarded(
    0,
    this->component.get_noArgsReturnGuarded_InputPort(0)
  );

  for (FwIndexType i = 0; i < 3; i++) {
    this->connect_to_noArgsReturnSync(
      i,
      this->component.get_noArgsReturnSync_InputPort(i)
    );
  }

  for (FwIndexType i = 0; i < 3; i++) {
    this->connect_to_noArgsSync(
      i,
      this->component.get_noArgsSync_InputPort(i)
    );
  }

  this->connect_to_typedAsync(
    0,
    this->component.get_typedAsync_InputPort(0)
  );

  this->connect_to_typedAsyncAssert(
    0,
    this->component.get_typedAsyncAssert_InputPort(0)
  );

  this->connect_to_typedAsyncBlockPriority(
    0,
    this->component.get_typedAsyncBlockPriority_InputPort(0)
  );

  this->connect_to_typedAsyncDropPriority(
    0,
    this->component.get_typedAsyncDropPriority_InputPort(0)
  );

  this->connect_to_typedGuarded(
    0,
    this->component.get_typedGuarded_InputPort(0)
  );

  this->connect_to_typedReturnGuarded(
    0,
    this->component.get_typedReturnGuarded_InputPort(0)
  );

  for (FwIndexType i = 0; i < 3; i++) {
    this->connect_to_typedReturnSync(
      i,
      this->component.get_typedReturnSync_InputPort(i)
    );
  }

  for (FwIndexType i = 0; i < 3; i++) {
    this->connect_to_typedSync(
      i,
      this->component.get_typedSync_InputPort(i)
    );
  }

  // Connect typed output ports

  this->component.set_noArgsOut_OutputPort(
    0,
    this->get_from_noArgsOut(0)
  );

  this->component.set_noArgsReturnOut_OutputPort(
    0,
    this->get_from_noArgsReturnOut(0)
  );

  this->component.set_typedOut_OutputPort(
    0,
    this->get_from_typedOut(0)
  );

  this->component.set_typedReturnOut_OutputPort(
    0,
    this->get_from_typedReturnOut(0)
  );
}

void ActiveGetProductsTester ::
  initComponents()
{
  this->init();
  this->component.init(ActiveGetProductsTester::TEST_INSTANCE_QUEUE_DEPTH, ActiveGetProductsTester::TEST_INSTANCE_ID);
}
