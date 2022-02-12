import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val toppingKinds = nextInt()
    val doughPrice = nextInt()
    val toppingPrice = nextInt()
    val doughCalorie = nextInt()
    val toppingCalories = ArrayList<Int>()

    for (i in 0 until toppingKinds) {
        toppingCalories.add(nextInt())
    }

    toppingCalories.sortDescending()

    var price = boj5545().calculate(toppingKinds, doughPrice, toppingPrice, doughCalorie, toppingCalories)
    println(price)
}

class boj5545 {

    fun calculate(
        toppingKinds: Int,
        doughPrice: Int,
        toppingPrice: Int,
        doughCalorie: Int,
        toppingCalories: ArrayList<Int>
    ): Int {
        var bestOfPizza = 0

        for (i in 0..toppingKinds) {
            val sumOf = toppingCalories.subList(0, i).sum()
            val calorieOfPrice = (doughCalorie + sumOf) / (doughPrice + toppingPrice * i)
            bestOfPizza = max(bestOfPizza, calorieOfPrice)
        }

        return bestOfPizza
    }
}