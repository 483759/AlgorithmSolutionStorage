import java.util.Scanner
import kotlin.math.roundToInt

fun main() = with(Scanner(System.`in`)) {
    val count = readLine()!!.toInt()
    val numbers = ArrayList<Int>().also {
        for (i in 0 until count) it += readLine()!!.toInt()
    }.sorted()

    println(numbers.average().roundToInt())
    println(numbers[(count - 1) / 2])
    numbers.groupingBy { it }
        .eachCount().toList()
        .sortedByDescending { it.second }
        .let {
            println(
                if (it.size > 1 && (it[0].second == it[1].second))
                    it[1].first
                else it[0].first
            )
        }
    println(numbers.last() - numbers.first())
}
