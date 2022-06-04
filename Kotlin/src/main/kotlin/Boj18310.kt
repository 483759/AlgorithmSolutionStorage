import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val numOfHouse = readLine()!!.toInt()
    val center = ((numOfHouse - 1) / 2)
    val location = readLine()!!
        .split(" ")
        .asSequence()
        .map { e -> Integer.valueOf(e) }
        .toList().sorted()

    println(location[center])
}