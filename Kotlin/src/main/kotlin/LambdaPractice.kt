fun printProblemCounts(responses: Collection<String>) : (Int) -> Int {
    var clientErrors = 0
    var serverErrors = 0

    responses.forEach {
        if (it.startsWith("4"))
            clientErrors++
        else if (it.startsWith("5"))
            serverErrors++
    }

    val foo = {error: Int -> error + clientErrors + serverErrors}

    return foo

    // println("$clientErrors client errors, $serverErrors server errors")
}

fun main() {
    val responses = listOf("200 OK", "418 I'm a teapot", "500 Internal Server Error")
    val problemCounts = printProblemCounts(responses)

    println(problemCounts(3))
}