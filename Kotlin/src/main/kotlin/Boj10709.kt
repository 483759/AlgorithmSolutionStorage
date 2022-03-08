import java.util.Scanner

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val size = readLine()!!.split(" ").map { e -> Integer.valueOf(e) }.toIntArray()
    for (i in 0 until size[0]) {
        var count = -1
        readLine()!!.split("").forEach { it ->
            when (it) {
                "." -> print("${if (count == -1) -1 else ++count} ")
                "c" -> {
                    print("0 ")
                    count = 0
                }
            }
        }
        println()
    }
}