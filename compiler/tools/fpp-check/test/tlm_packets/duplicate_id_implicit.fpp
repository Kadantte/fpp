topology T {

  instance c1
  instance c2

  telemetry packets P {

    packet P1 level 0 {
      c1.T
    }

    packet P2 id 0 level 1 {
      c2.T
    }

  }

}
