package fpp.compiler.analysis

import fpp.compiler.ast._
import fpp.compiler.util._

/** Analyze uses */
trait UseAnalyzer extends TypeExpressionAnalyzer {

  def componentInstanceUse(a: Analysis, node: AstNode[Ast.QualIdent], use: Name.Qualified) = default(a)

  def exprUse(a: Analysis, node: AstNode[Ast.Expr], use: Name.Qualified) = default(a)

  def portInstanceUse(a: Analysis, node: AstNode[Ast.QualIdent], use: Name.Qualified) = default(a)

  def topologyUse(a: Analysis, node: AstNode[Ast.QualIdent], use: Name.Qualified) = default(a)

  def typeNameUse(a: Analysis, node: AstNode[Ast.TypeName], use: Name.Qualified) = default(a)

  override def exprDotNode(a: Analysis, node: AstNode[Ast.Expr], e: Ast.ExprDot) = {
    def nameOpt(e: Ast.Expr, qualifier: List[Name.Unqualified]): Option[Name.Qualified] = {
      e match {
        case Ast.ExprIdent(id) => {
          val list = id :: qualifier
          val use = Name.Qualified.fromIdentList(list)
          Some(use)
        }
        case Ast.ExprDot(e1, id) => nameOpt(e1.getData, id :: qualifier)
        case _ => None
      }
    }
    nameOpt(e, Nil) match {
      case Some(use) => exprUse(a, node, use)
      case None => Right(a)
    }
  }

  override def exprIdentNode(a: Analysis, node: AstNode[Ast.Expr], e: Ast.ExprIdent) = {
    val use = Name.Qualified(Nil, e.value)
    exprUse(a, node, use)
  }

  override def exprNode(a: Analysis, node: AstNode[Ast.Expr]): Result = matchExprNode(a, node)

  override def specCompInstanceAnnotatedNode(a: Analysis, node: Ast.Annotated[AstNode[Ast.SpecCompInstance]]) = {
    val (_, node1, _) = node
    val data = node1.getData
    qualIdentNode (componentInstanceUse) (a, data.instance)
  }

  override def specConnectionGraphAnnotatedNode(
    a: Analysis, node: Ast.Annotated[AstNode[Ast.SpecConnectionGraph]]) = {
    def connection(a: Analysis, connection: Ast.SpecConnectionGraph.Connection): Result = {
      for {
        a <- qualIdentNode (portInstanceUse) (a, connection.fromPort)
        a <- opt(exprNode)(a, connection.fromIndex)
        a <- qualIdentNode (portInstanceUse) (a, connection.toPort)
        a <- opt(exprNode)(a, connection.toIndex)
      } yield a
    }
    val (_, node1, _) = node
    val data = node1.getData
    data match {
      case direct @ Ast.SpecConnectionGraph.Direct(_, _) => visitList(a, direct.connections, connection)
      case pattern @ Ast.SpecConnectionGraph.Pattern(_, _, _) => for {
        a <- qualIdentNode (portInstanceUse) (a, pattern.source)
        a <- visitList(a, pattern.targets, qualIdentNode (portInstanceUse))
        a <- exprNode(a, pattern.pattern)
      } yield a
    }
  }

  override def specInitAnnotatedNode(a: Analysis, node: Ast.Annotated[AstNode[Ast.SpecInit]]) = {
    val (_, node1, _) = node
    val data = node1.getData
    for {
      a <- qualIdentNode (componentInstanceUse) (a, data.instance)
      a <- exprNode(a, data.phase)
    } yield a
  }

  override def specPortInstanceAnnotatedNode(a: Analysis, node: Ast.Annotated[AstNode[Ast.SpecPortInstance]]) = {
    val (_, node1, _) = node
    val data = node1.getData
    data match {
      case general @ Ast.SpecPortInstance.General(_, _, _, _, _, _) =>
        for {
          a <- opt(exprNode)(a, general.size)
          a <- opt(qualIdentNode(portInstanceUse))(a, general.port)
          a <- opt(exprNode)(a, general.priority)
        } yield a
      case _ => Right(a)
    }
  }

  override def specTopImportAnnotatedNode(a: Analysis, node: Ast.Annotated[AstNode[Ast.SpecTopImport]]) = {
    val (_, node1, _) = node
    val data = node1.getData
    qualIdentNode(topologyUse)(a, data.top)
  }

  override def specUnusedPortsAnnotatedNode(a: Analysis, node: Ast.Annotated[AstNode[Ast.SpecUnusedPorts]]) = {
    val (_, node1, _) = node
    val data = node1.getData
    visitList(a, data.ports, qualIdentNode (portInstanceUse))
  }

  override def typeNameNode(a: Analysis, node: AstNode[Ast.TypeName]) = matchTypeNameNode(a, node)

  override def typeNameQualIdentNode(a: Analysis, node: AstNode[Ast.TypeName], tn: Ast.TypeNameQualIdent) = {
    val use = Name.Qualified.fromIdentList(tn.name)
    typeNameUse(a, node, use)
  }

  private def qualIdentNode 
    (f: (Analysis, AstNode[Ast.QualIdent], Name.Qualified) => Result) 
    (a: Analysis, node: AstNode[Ast.QualIdent]): Result = {
    val use = Name.Qualified.fromIdentList(node.getData)
    f(a, node, use)
  }

}
