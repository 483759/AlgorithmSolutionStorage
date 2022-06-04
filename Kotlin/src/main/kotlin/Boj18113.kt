import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val (n, k, m) = readLine()!!.split(" ").map { e -> e.toLong() }

    var arr = ArrayList<Long>().apply {
        (0 until n).forEach { i ->
            this.add(readLine()!!.toLong())
        }
        this.sortDescending()
    }

    var left: Long = 0
    var right = arr[0] + 1
    while (left + 1 < right) {
        val mid: Long = (left + right) / 2

        var cnt = 0L
        for (a in arr) {
            var value = a - if (a <= k) {
                break
            } else if (a < 2 * k) k
            else 2 * k

            if (value >= mid) cnt += value / mid
        }

        if (cnt >= m) left = mid
        else right = mid
    }

    println(if (left == 0L) -1 else left)
}
