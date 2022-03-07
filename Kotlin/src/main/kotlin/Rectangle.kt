fun main() {
    val rectangle = Rectangle(5, 3)
    val square = Rectangle(4, 4)

    // println(rectangle.isSquare)
    // println(square.isSquare)
}

class Rectangle(private val height: Int, private val width: Int) {
    val isSquare: Boolean
        get() = height == width
}