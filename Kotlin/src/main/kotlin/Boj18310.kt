import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val numOfHouse = readLine()!!.toInt()
    val location = readLine()!!
        .split(" ")
        .map { e -> Integer.valueOf(e) }
        .toList().sorted()

    val average = (location.sum())/(location.size)
    println(location[location.binarySearch(average)])
}