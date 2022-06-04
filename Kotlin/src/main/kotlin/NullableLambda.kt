var canReturnNull: (Int, Int) -> Int? = { x, y -> null }
var funOrNull: ((Int, Int) -> Int)? = null

fun main() {
    println(canReturnNull(1, 2))
}