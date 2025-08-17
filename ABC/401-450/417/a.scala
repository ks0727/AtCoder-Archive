object Main extends App{
    val Array(n,a,b) = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    val s = scala.io.StdIn.readLine()
    println(s.slice(a,n-b))
}