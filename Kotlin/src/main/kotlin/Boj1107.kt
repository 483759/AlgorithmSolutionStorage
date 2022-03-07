import java.util.LinkedList
import java.util.Queue
import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val chanel = readLine()!!.toInt()
    val brokenButtonNum = readLine()!!.toInt()
    
    val brokenButtons = readLine()!!
        .split(" ")
        .map { e -> Integer.valueOf(e) }
        .toList()

    val cur = 100
    val queue = LinkedList<Int>()

    initialize(cur, queue)
    println(travel(chanel, queue))
}

fun initialize(
    cur: Int,
    queue: Queue<Int>
) {
    queue.add(cur + 1)
    queue.add(cur - 1)
    (0..9)
        .forEach { i ->
            queue.add(i)
        }
}

fun travel(
    des: Int,
    queue: Queue<Int>
) : Int {
    var min = 0

    while (queue.isNotEmpty()) {
        min++
        val size = queue.size

        (0 until size).forEach {
            val cur = queue.poll()
            if (cur == des) return min

            queue.add(cur + 1)
            if (cur > 1) queue.add(cur - 1)
            (0..9)
                .forEach { i ->
                    queue.add(cur * 10 + i)
                }
        }
    }

    return 0
}