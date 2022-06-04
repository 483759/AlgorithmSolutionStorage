import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = readLine()!!.toInt()
    var answer = 0

    var (left, right) = 1 to 1
    while (right in left..n) {
        var sumOfNumbers = calculateSumOfNumbers(left, right)
        if (sumOfNumbers <= n) {
            right++
            if (sumOfNumbers == n) {
                answer++
            }
        } else if (sumOfNumbers > n) {
            left++
        }
    }
    println(answer)
}

fun calculateSumOfNumbers(start: Int, end: Int): Int {
    return (end * (end + 1)) / 2 - (start * (start - 1)) / 2
}