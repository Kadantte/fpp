package fpp.compiler

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.codegen._
import fpp.compiler.syntax._
import fpp.compiler.transform._
import fpp.compiler.util._
import io.circe.syntax._
import io.circe._
import io.circe.generic.semiauto._
import io.circe.generic.auto._
import scala.util.parsing.input.Position

case class JsonEncoder(
  tul: List[Ast.TransUnit] = List.empty[Ast.TransUnit],
  anylisis: Analysis = Analysis()
)
{
  implicit val binopEncoder: Encoder[Ast.Binop] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val unopEncoder: Encoder[Ast.Unop] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val componentKindEncoder: Encoder[Ast.ComponentKind] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val typeIntEncoder: Encoder[Ast.TypeInt] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val typeFloatEncoder: Encoder[Ast.TypeFloat] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val queueFullEncoder: Encoder[Ast.QueueFull] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val updateEncoder: Encoder[Ast.SpecTlmChannel.Update] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val limitKindEncoder: Encoder[Ast.SpecTlmChannel.LimitKind] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val generalKindEncoder: Encoder[Ast.SpecPortInstance.GeneralKind] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val specialInputKindEncoder: Encoder[Ast.SpecPortInstance.SpecialInputKind] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val specialKindEncoder: Encoder[Ast.SpecPortInstance.SpecialKind] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
  implicit val visibilityEncoder: Encoder[Ast.Visibility] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))

  //implicit val specLockKindEncoder: Encoder[Map[(Ast.SpecLoc.Kind, Name.Qualified), Ast.SpecLoc]] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))
 
  //implicit val patternEncoder: Encoder[Ast.SpecConnectionGraph.Pattern] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))

  //implicit val typeQualEncoder: Encoder[Ast.QualIdent] = Encoder.encodeString.contramap(getUnqualifiedClassName(_)) //Needs to be refactored becuase this wont print out full list
  //implicit val specCommandEncoder: Encoder[Ast.SpecCommand] = Encoder.encodeString.contramap(getUnqualifiedClassName(_)) 
  //implicit val specEventEncoder: Encoder[Ast.SpecEvent] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))

  implicit def optionEncoder[A](implicit encoder: Encoder[A]): Encoder[Option[A]] = {
    case Some(value) => Json.obj("Option" -> Json.obj("Some" -> encoder(value)))
    case None => Json.obj("Option" -> Json.fromString("None"))
  }

  implicit val structTypeMemberEncoder: Encoder[Ast.Annotated[AstNode[Ast.StructTypeMember]]] = Encoder.instance { 
      aNode => addAnnotationJson(aNode._1, addTypeName(aNode._2, aNode._2.asJson), aNode._3)
  }

  implicit val defEnumConstantEncoder: Encoder[Ast.Annotated[AstNode[Ast.DefEnumConstant]]] = Encoder.instance { 
      aNode => addAnnotationJson(aNode._1, addTypeName(aNode._2, aNode._2.asJson), aNode._3)
  }

  implicit val specInitEncoder: Encoder[Ast.Annotated[AstNode[Ast.SpecInit]]] = Encoder.instance { 
      aNode => addAnnotationJson(aNode._1, addTypeName(aNode._2, aNode._2.asJson), aNode._3)
  }

  implicit val formalParamEncoder: Encoder[Ast.Annotated[AstNode[Ast.FormalParam]]] = Encoder.instance { 
      aNode => addAnnotationJson(aNode._1, addTypeName(aNode._2, aNode._2.asJson), aNode._3)
  }

  implicit val qualIdentEncoder: Encoder[Ast.QualIdent] = Encoder.instance (
  (q: Ast.QualIdent) => q match {
      case ident: Ast.QualIdent.Unqualified => addTypeName(ident, ident.asJson)
      case ident: Ast.QualIdent.Qualified => addTypeName(ident, ident.asJson)
  })

  implicit val moduleMemberEncoder: Encoder[Ast.ModuleMember] = Encoder.instance (
  (m: Ast.ModuleMember) => m.node._2 match {
      case aNode: Ast.ModuleMember.DefAbsType => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefArray => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefComponent => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefComponentInstance => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefConstant => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefEnum => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefModule => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefPort => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefStruct => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.DefTopology => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.SpecInclude => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
      case aNode: Ast.ModuleMember.SpecLoc => addAnnotationJson(m.node._1, addTypeName(aNode, aNode.asJson), m.node._3)
  })

  implicit val exprEncoder: Encoder[Ast.Expr] = Encoder.instance (
  (e: Ast.Expr) => e match {
      case expr: Ast.ExprArray => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprBinop => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprDot => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprParen => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprIdent => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprStruct => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprUnop => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprLiteralInt => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprLiteralBool => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprLiteralFloat => addTypeName(expr, expr.asJson)
      case expr: Ast.ExprLiteralString => addTypeName(expr, expr.asJson)
  })

  implicit val componentMemberEncoder: Encoder[Ast.ComponentMember] = Encoder.instance (
  (c: Ast.ComponentMember) => c.node._2 match {
      case aNode: Ast.ComponentMember.DefAbsType => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.DefArray => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.DefConstant => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.DefEnum => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.DefStruct => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecCommand => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecEvent => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecInclude => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecInternalPort => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecParam => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecPortInstance => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecPortMatching => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
      case aNode: Ast.ComponentMember.SpecTlmChannel => addAnnotationJson(c.node._1, addTypeName(aNode, aNode.asJson), c.node._3)
  })


  implicit val typeNameEncoder: Encoder[Ast.TypeName] = Encoder.instance (
  (t: Ast.TypeName) => t match {
      case t: Ast.TypeNameFloat => addTypeName(t, t.asJson)
      case t: Ast.TypeNameInt => addTypeName(t, t.asJson)
      case t: Ast.TypeNameQualIdent => addTypeName(t, t.asJson)
      case t: Ast.TypeNameString => addTypeName(t, t.asJson)
      case Ast.TypeNameBool => addTypeName(t, Json.fromString("TypeNameBool"))
  })

  implicit val topologyMemberEncoder: Encoder[Ast.TopologyMember] = Encoder.instance (
  (t: Ast.TopologyMember) => t.node._2 match {
      case aNode: Ast.TopologyMember.SpecCompInstance => 
        addAnnotationJson(t.node._1, addTypeName(aNode, aNode.asJson), t.node._3)
      case aNode: Ast.TopologyMember.SpecConnectionGraph => 
        addAnnotationJson(t.node._1, addTypeName(aNode, aNode.asJson), t.node._3)
      case aNode: Ast.TopologyMember.SpecInclude => 
        addAnnotationJson(t.node._1, addTypeName(aNode, aNode.asJson), t.node._3)
      case aNode: Ast.TopologyMember.SpecTopImport => 
        addAnnotationJson(t.node._1, addTypeName(aNode, aNode.asJson), t.node._3)
  })

  def printAstJson(): Json = tul.asJson

  def addTypeName[T](x: T, json: Json): Json = Json.obj(getUnqualifiedClassName(x) -> json)


  def getUnqualifiedClassName[T] (x: T): String = 
    x.getClass.getName.replaceAll("\\A.*\\.", "").replaceAll("\\$$", "").replaceAll("\\A.*\\$", "")
    
  def addAnnotationJson(pre: List[String], data: Json, post: List[String]): Json = 
    Json.obj("preAnnotation" -> pre.asJson, "data" -> data, "postAnnotation" -> post.asJson)

//******************************************************************************************************************************************************************
//******************************************************************************************************************************************************************
//******************************************************************************************************************************************************************


  implicit val fileEncoder: Encoder[File] = new Encoder[File] {
    override def apply(file: File): Json = Json.fromString(file.toString)
  }

  implicit val positionEncoder: Encoder[Position] = new Encoder[Position] {
    override def apply(position: Position): Json = Json.fromString(position.toString)
  }

  implicit val locationEncoder: Encoder[Location] = new Encoder[Location] {
    override def apply(location: Location): Json = Json.obj(
      "file" -> location.file.asJson,
      "pos" -> location.pos.asJson,
      "includingLoc" -> location.includingLoc.asJson
    )
  }

  def printLocationsMapJson(): Json = Locations.hashMapToListOfPairs().asJson

//******************************************************************************************************************************************************************
//******************************************************************************************************************************************************************
//******************************************************************************************************************************************************************
implicit val symbolMapEncoder: Encoder[Map[Symbol, Symbol]] = Encoder.instance { symbols =>
    symbols.toList.map {
      case (key, value) => key.getNodeId -> value.getNodeId
    }.toMap.asJson
  }

  implicit val scopeMapEncoder: Encoder[Map[Symbol, Scope]] = Encoder.instance { symbols =>
    symbols.toList.map {
      case (key, value) => key.toString -> value.toString
    }.toMap.asJson
  }

    implicit val componentMapEncoder: Encoder[Map[Symbol.Component, Component]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.getNodeId -> value.asJson
      }.toMap.asJson
    }

    implicit val specialKindMapEncoder: Encoder[Map[Ast.SpecPortInstance.SpecialKind, PortInstance.Special]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }

    implicit val commandMapEncoder: Encoder[Map[Command.Opcode, Command]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.asJson
      }.toMap.asJson
    }

    implicit val tlmChannelMapEncoder: Encoder[Map[TlmChannel.Id, TlmChannel]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }
  //
    implicit val eventMapEncoder: Encoder[Map[Event.Id, Event]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.asJson
      }.toMap.asJson
    }
//
    implicit val paramMapEncoder: Encoder[Map[Param.Id, Param]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }

    implicit val componentInstanceMapEncoder: Encoder[Map[Symbol.ComponentInstance, ComponentInstance]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.getNodeId -> value.asJson
      }.toMap.asJson
    }

    implicit val topologyMapEncoder: Encoder[Map[Symbol.Topology, Topology]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.getNodeId -> value.asJson
      }.toMap.asJson
    }

    implicit val locationSpecifierMapEncoder: Encoder[Map[(Ast.SpecLoc.Kind, Name.Qualified), Ast.SpecLoc]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.asJson
      }.toMap.asJson
    }

    implicit val locationTopologyMapEncoder: Encoder[Map[Symbol.Topology, Location]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.getNodeId -> value.asJson
      }.toMap.asJson
    }

    implicit val componentInstanceLocationMapEncoder: Encoder[Map[ComponentInstance, (Ast.Visibility, Location)]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }

    implicit val connectionGraphMapEncoder: Encoder[Map[Ast.SpecConnectionGraph.Pattern.Kind, ConnectionPattern]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }

     implicit val typeMapEncoder: Encoder[Map[AstNode.Id, Type]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }

    implicit val valueMapEncoder: Encoder[Map[AstNode.Id, Value]] = Encoder.instance { symbols =>
      symbols.toList.map {
        case (key, value) => key.toString -> value.toString
      }.toMap.asJson
    }


    implicit val nestedScopeEncoder: Encoder[NestedScope] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))

    implicit val topologyEncoder: Encoder[Topology] = Encoder.encodeString.contramap(getUnqualifiedClassName(_))



    def printAnalysisJson(): Json = anylisis.asJson
 
}
/**
##Stuff that works
inputFileSet
level
dependencyFileSets
directDependencyFileSet
missingDependencyFileSet
includedFileSet
scopeNameList
parentSymbol
useDefMap
visitedSymbolSet
useDefSymbolSet
useDefMatchingList
usedSymbolSet

##Verify Format: 
parentSymbolMap (addressible error?)
symbolScopeMap (addressible error?)
componentMap (addressible error?)
component (addressible error?)
componentInstanceMap (addressible error?)
componentInstance (addressible error?)
topologyMap (addressible error?)
locationSpecifierMap (addressible error?)
typeMap (Huge inline error [Could be an infinite recur problem])
valueMap (Huge inline error [Could be an infinite recur problem])


##Doest Work:
nestedScope (Strange error, gc problem) 
topology (Strange error, gc problem) 
*/
