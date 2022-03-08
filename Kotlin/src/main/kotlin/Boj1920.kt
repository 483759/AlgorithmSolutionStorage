import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    readLine()
    val numbers = readLine()!!.split(" ")
        .map { e -> Integer.valueOf(e) }
        .toSet()
    readLine()
    readLine()!!.split(" ")
        .forEach { e ->
            println(if (numbers.contains(Integer.valueOf(e))) 1 else 0)
        }
}
