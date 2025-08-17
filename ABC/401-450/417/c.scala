object Main extends App{
    val n : Long = scala.io.StdIn.readInt()
    val a : Array[Int] = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    val (_, ans) = (0 until n.toInt).foldLeft((Map.empty[Long,Long].withDefaultValue(0L),0L)){
        case ((mp, sum), j) =>{
            val Lj = j.toLong - a(j)
            val add = mp(Lj)
            val Rj = j.toLong + a(j)
            val cnt2 = mp.updated(Rj,mp(Rj)+1L)
            (cnt2, sum + add)
        }
    }
    println(ans)
}