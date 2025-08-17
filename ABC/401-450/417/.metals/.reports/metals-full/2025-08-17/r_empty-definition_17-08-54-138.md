error id: file://<WORKSPACE>/c.scala:scala/io/StdIn#readInt().
file://<WORKSPACE>/c.scala
empty definition using pc, found symbol in pc: scala/io/StdIn#readInt().
empty definition using semanticdb
empty definition using fallback
non-local guesses:
	 -scala/io/StdIn.readInt.
	 -scala/io/StdIn.readInt#
	 -scala/io/StdIn.readInt().
	 -scala/Predef.scala.io.StdIn.readInt.
	 -scala/Predef.scala.io.StdIn.readInt#
	 -scala/Predef.scala.io.StdIn.readInt().
offset: 60
uri: file://<WORKSPACE>/c.scala
text:
```scala
object Main extends App{
    val n : Long = scala.io.StdIn.r@@eadInt()
    val a : Array = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    println(n)
}
```


#### Short summary: 

empty definition using pc, found symbol in pc: scala/io/StdIn#readInt().