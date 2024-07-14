// ======================================================================
// \title  BasicTopologyAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Basic topology
// ======================================================================

#include "BasicTopologyAc.hpp"

namespace M {


  // ----------------------------------------------------------------------
  // Component configuration objects
  // ----------------------------------------------------------------------

  namespace ConfigObjects {

    namespace M_active2 {
      U32 x = 0;
    }

  }


  // ----------------------------------------------------------------------
  // Component instances
  // ----------------------------------------------------------------------

  Active M::active1(FW_OPTIONAL_NAME("M::active1"));

  Active M::active2;

  Active M::active3(FW_OPTIONAL_NAME("M::active3"));

  Passive M::passive1(FW_OPTIONAL_NAME("M::passive1"));

  ConcretePassive M::passive2(FW_OPTIONAL_NAME("M::passive2"));

  // ----------------------------------------------------------------------
  // Helper functions
  // ----------------------------------------------------------------------

  void initComponents(const TopologyState& state) {
    M::active1.init(QueueSizes::M_active1, InstanceIds::M_active1);
    M::active2.initSpecial();
    M::active3.init(QueueSizes::M_active3, InstanceIds::M_active3);
    M::passive1.init(InstanceIds::M_passive1);
    M::passive2.init(InstanceIds::M_passive2);
  }

  void configComponents(const TopologyState& state) {
    M::active2.config();
  }

  void setBaseIds() {
    M::active1.setIdBase(BaseIds::M_active1);
    M::active2.setIdBase(BaseIds::M_active2);
    M::active3.setIdBase(BaseIds::M_active3);
    M::passive1.setIdBase(BaseIds::M_passive1);
    M::passive2.setIdBase(BaseIds::M_passive2);
  }

  void connectComponents() {

    // C1
    M::passive1.set_p_OutputPort(
        0,
        M::active1.get_p_InputPort(0)
    );

    // C2
    M::passive2.set_p_OutputPort(
        0,
        M::active2.get_p_InputPort(0)
    );
  }

  void regCommands() {
    // Nothing to do
  }

  void readParameters() {
    // Nothing to do
  }

  void loadParameters() {
    // Nothing to do
  }

  void startTasks(const TopologyState& state) {
    M::active1.start(
      static_cast<Os::Task::ParamType>(Priorities::M_active1),
      static_cast<Os::Task::ParamType>(StackSizes::M_active1),
      static_cast<Os::Task::ParamType>(CPUs::M_active1),
      static_cast<Os::Task::ParamType>(TaskIds::M_active1)
    );
    M::active2.startSpecial();
    M::active3.start(
      Os::Task::TASK_DEFAULT, // Default priority
      Os::Task::TASK_DEFAULT, // Default stack size
      Os::Task::TASK_DEFAULT, // Default CPU
      static_cast<Os::Task::ParamType>(TaskIds::M_active3)
    );
  }

  void stopTasks(const TopologyState& state) {
    M::active1.exit();
    M::active2.stopSpecial();
    M::active3.exit();
  }

  void freeThreads(const TopologyState& state) {
    (void) M::active1.ActiveComponentBase::join();
    M::active2.freeSpecial();
    (void) M::active3.ActiveComponentBase::join();
  }

  void tearDownComponents(const TopologyState& state) {
    M::active2.tearDown();
  }

  // ----------------------------------------------------------------------
  // Setup and teardown functions
  // ----------------------------------------------------------------------

  void setup(const TopologyState& state) {
    initComponents(state);
    configComponents(state);
    setBaseIds();
    connectComponents();
    regCommands();
    readParameters();
    loadParameters();
    startTasks(state);
  }

  void teardown(const TopologyState& state) {
    stopTasks(state);
    freeThreads(state);
    tearDownComponents(state);
  }

}
