. ./fpp-flags.sh

basic()
{
  update "$fpp_flags" Basic
  move_cpp BasicStateMachine
}

basic_u32()
{
  update "$fpp_flags" BasicU32
  move_cpp BasicU32StateMachine
}

choice_to_choice()
{
  update "$fpp_flags" JunctionToJunction
  move_cpp JunctionToJunctionStateMachine
}

choice_to_state()
{
  update "$fpp_flags" JunctionToState
  move_cpp JunctionToStateStateMachine
}

input_pair_u16_u32()
{
  update "$fpp_flags" InputPairU16U32
  move_cpp InputPairU16U32StateMachine
}

sequence()
{
  update "$fpp_flags" Sequence
  move_cpp SequenceStateMachine
}

sequence_u32()
{
  update "$fpp_flags" SequenceU32
  move_cpp SequenceU32StateMachine
}
