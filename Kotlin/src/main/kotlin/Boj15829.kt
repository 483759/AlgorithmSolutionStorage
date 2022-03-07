import java.util.Scanner
import kotlin.math.pow

const val r = 31L
const val M = 1234567891L

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val L = readLine()!!
    val input = readLine()!!
    var hashValue: Long = 0
    var exp: Long = 1

    for (i in input.indices) {
        hashValue = (hashValue + (input[i] - 'a' + 1) * exp) % M
        exp = (exp * r) % M
    }
    println(hashValue)
}