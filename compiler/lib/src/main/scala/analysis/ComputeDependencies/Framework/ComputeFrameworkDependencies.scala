package fpp.compiler.analysis

import fpp.compiler.ast._

/** Compute framework dependencies */
object ComputeFrameworkDependencies extends AstStateVisitor {

  type State = Set[FrameworkDependency]

  override def defComponentAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefComponent]]
  ) = {
    val (_, node, _) = aNode
    val data = node.data
    val d = data.kind match {
      case Ast.ComponentKind.Passive => FrameworkDependency.FwComp
      case _ => FrameworkDependency.FwCompQueued
    }
    visitList(s + d, data.members, matchComponentMember)
  }

  override def specPortInstanceAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.SpecPortInstance]]
  ) = {
    val (_, node, _) = aNode
    node.data match {
      case general: Ast.SpecPortInstance.General =>
        general.kind match {
          case Ast.SpecPortInstance.GuardedInput =>
            Right(s + FrameworkDependency.Os)
          case _ => Right(s)
        }
      case _ => Right(s)
    }
  }

  override def transUnit(s: State, tu: Ast.TransUnit) = 
    visitList(s, tu.members, matchTuMember)

}
