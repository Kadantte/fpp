package fpp.compiler.codegen

/** Utilities for constructing XML Tags */
object XmlTags extends LineUtils {

  def closeTag(name: String): String = s"</$name>"

  def openCloseTag(name: String, pairs: List[(String, String)] = Nil): String = openTagPrefix(name, pairs) ++ "/>"

  def openTag(name: String, pairs: List[(String, String)] = Nil): String = openTagPrefix(name, pairs) ++ ">"

  def quoted(s: String): String = {
    // Add the enclosing quotation marks for the XML attribute
    val q = "\""
    s"$q$s$q"
  }

  def escaped(s: String): String = {
    // These are the characters that must be replaced in an XML attribute
    val replacements = List(
      ("&", "&amp;"),
      ("'", "&apos;"),
      ("<", "&lt;"),
      (">", "&gt;"),
      ("\"", "&quot;"),
    )
    replacements.foldLeft (s) ({ case (s, (a, b)) => s.replaceAll(a, b) })
  }

  def taggedLines (tags: (String, String)) (ls: List[Line]): List[Line] = {
    val (openTag, closeTag) = tags
    (line(openTag) :: ls) :+ line(closeTag)
  }

  def taggedLines (name: String, pairs: List[(String, String)] = Nil) (ls: List[Line]): List[Line] =
    ls match {
      case Nil => lines(openCloseTag(name, pairs))
      case _ => taggedLines (tags(name, pairs)) (ls)
    }

  def taggedLinesOpt (name: String, pairs: List[(String, String)] = Nil) (ls: List[Line]): List[Line] =
    ls match {
      case Nil => Nil
      case ls1 => taggedLines (name, pairs) (ls1)
    }

  def taggedString (tags: (String, String)) (s: String): String = {
    val (openTag, closeTag) = tags
    openTag ++ s ++ closeTag
  }

  def tags(name: String, pairs: List[(String, String)] = Nil): (String, String) = (openTag(name, pairs), closeTag(name))

  private def openTagPrefix(name: String, pairs: List[(String, String)]) =
    pairs.foldLeft(s"<$name")({ case (s, key -> value) => s ++ s" $key=${quoted(escaped(value))}" })

}
