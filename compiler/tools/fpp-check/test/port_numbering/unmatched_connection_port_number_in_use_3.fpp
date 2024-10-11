module M {

  port P

  passive component C1 {

    output port pOut: [4] P
    sync input port pIn: [4] P

    match pOut with pIn
  }

  instance c1: C1 base id 0x100
  instance c2: C1 base id 0x200
  instance c3: C1 base id 0x300

  topology T {

    instance c1
    instance c2
    instance c3

    connections P {

      c1.pOut -> c2.pIn[0]
      c2.pOut -> c1.pIn
      unmatched c2.pOut[0] -> c3.pIn
    }
  }

}
