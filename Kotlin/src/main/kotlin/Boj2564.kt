class BasicObject {
    val message = object {
        fun get() = "Hello World"
    }
}

class CompanionObject {
    companion object {
        fun get() = "Hello World"
    }
}