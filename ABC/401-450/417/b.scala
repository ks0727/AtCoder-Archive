object Main extends App{
    val Array(n,m) = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    val a = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    val b = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    val result = b.foldLeft(a){(curA, bi) =>
        curA.indexOf(bi) match{
            case -1 => curA
            case idx => curA.patch(idx,Nil,1)
        }
    }
    println(result.mkString(" "))
}