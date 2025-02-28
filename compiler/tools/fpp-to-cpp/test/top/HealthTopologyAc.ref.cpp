// ======================================================================
// \title  HealthTopologyAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Health topology
// ======================================================================

#include "HealthTopologyAc.hpp"

// ----------------------------------------------------------------------
// Component instances
// ----------------------------------------------------------------------

namespace M {

  M::C c1(FW_OPTIONAL_NAME("c1"));

}

namespace M {

  M::C c2(FW_OPTIONAL_NAME("c2"));

}

namespace M {

  Svc::Health health(FW_OPTIONAL_NAME("health"));

}

namespace M {


  // ----------------------------------------------------------------------
  // Component configuration objects
  // ----------------------------------------------------------------------

  namespace ConfigObjects {

    namespace M_health {
      Svc::Health::PingEntry pingEntries[NUM_PING_ENTRIES] = {
        {
          PingEntries::M_c1::WARN,
          PingEntries::M_c1::FATAL,
          "M_c1"
        },
        {
          PingEntries::M_c2::WARN,
          PingEntries::M_c2::FATAL,
          "M_c2"
        },
      };
    }

  }


  // ----------------------------------------------------------------------
  // Helper functions
  // ----------------------------------------------------------------------

  void initComponents(const TopologyState& state) {
    M::c1.init(InstanceIds::M_c1);
    M::c2.init(InstanceIds::M_c2);
    M::health.init(InstanceIds::M_health);
  }

  void configComponents(const TopologyState& state) {
    // Nothing to do
  }

  void setBaseIds() {
    M::health.setIdBase(BaseIds::M_health);
    M::c1.setIdBase(BaseIds::M_c1);
    M::c2.setIdBase(BaseIds::M_c2);
  }

  void connectComponents() {

    // Health
    M::c1.set_pingOut_OutputPort(
        0,
        M::health.get_pingIn_InputPort(0)
    );
    M::c2.set_pingOut_OutputPort(
        0,
        M::health.get_pingIn_InputPort(1)
    );
    M::health.set_pingOut_OutputPort(
        0,
        M::c1.get_pingIn_InputPort(0)
    );
    M::health.set_pingOut_OutputPort(
        1,
        M::c2.get_pingIn_InputPort(0)
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
    // Nothing to do
  }

  void stopTasks(const TopologyState& state) {
    // Nothing to do
  }

  void freeThreads(const TopologyState& state) {
    // Nothing to do
  }

  void tearDownComponents(const TopologyState& state) {
    // Nothing to do
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
