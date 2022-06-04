import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = readLine()!!.toInt()

    val board: List<List<String>> = ArrayList<ArrayList<String>>()
    for (i in 0 until n) {
        (readLine()!!
            .split(" ")
            .toList()
        )
    }
}
