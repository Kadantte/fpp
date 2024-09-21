package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.ast._

/** Utilities for writing C++ state machines */
abstract class StateMachineCppWriterUtils(
  s: CppWriterState,
  aNode: Ast.Annotated[AstNode[Ast.DefStateMachine]]
) extends CppWriterUtils {

  val symbol = Symbol.StateMachine(aNode)

  val stateMachine: StateMachine = s.a.stateMachineMap(symbol)

  val sma = stateMachine.sma

  val name = s.getName(symbol)

  val className = s"${name}StateMachineBase"

  val fileName = ComputeCppFiles.FileNames.getStateMachine(
    name,
    StateMachine.Kind.Internal
  )

  val namespaceIdentList = s.getNamespaceIdentList(symbol)

  val typeCppWriter = TypeCppWriter(s)

  val uninitStateName = "__FPRIME_AC_UNINITIALIZED"

  val initialTransitionName = "__FPRIME_AC_INITIAL_TRANSITION"

  val leafStates = StateMachine.getLeafStates(symbol)

  def writeSmSymbolName(state: StateMachineSymbol) =
    CppWriterState.identFromQualifiedSmSymbolName(sma, state)

  val commentedLeafStateNames =
    leafStates.toList.map(
      state => (
        AnnotationCppWriter.writePreComment(state),
        writeSmSymbolName(StateMachineSymbol.State(state))
      )
    ).sortBy(_._2)

  val actionSymbols =
    StateMachine.getActions(aNode._2.data).map(StateMachineSymbol.Action(_))

  val valueParamName = "value"

  def getActionFunctionName(sym: StateMachineSymbol.Action): String =
    s"action_${sym.getUnqualifiedName}"

  val signalSymbols =
    StateMachine.getSignals(aNode._2.data).map(StateMachineSymbol.Signal(_))

  val signalParamName = "signal"

  val signalParam = CppDoc.Function.Param(
    CppDoc.Type("Signal"),
    signalParamName,
    Some("The signal")
  )

  val commentedSignalNames =
    signalSymbols.map(
      symbol => (
        AnnotationCppWriter.writePreComment(symbol.node),
        writeSmSymbolName(symbol)
      )
    ).sortBy(_._2)

  def writeActionCall (signalArg: String) (valueArgOpt: Option[String]) (sym: StateMachineSymbol.Action) = {
    val args = (valueArgOpt, sym.node._2.data.typeName) match {
      case (Some(valueArg), Some(_)) => s"$signalArg, $valueArg"
      case _ => signalArg
    }
    val actionFunctionName = getActionFunctionName(sym)
    lines(s"this->$actionFunctionName($args);")
  }

  val writeNoValueActionCall = (signalArg: String) => writeActionCall (signalArg) (None)

  def getEnterFunctionName(symbol: StateMachineSymbol) =
    s"enter_${writeSmSymbolName(symbol)}"

  def writeStateUpdate(sym: StateMachineSymbol.State) = {
    val stateName = writeSmSymbolName(sym)
    lines(s"this->m_state = State::$stateName;")
  }

  def writeEnterCall (signalArg: String) (sym: StateMachineSymbol) = {
    val enterFunctionName = getEnterFunctionName(sym)
    lines(s"this->$enterFunctionName($signalArg);")
  }

}
