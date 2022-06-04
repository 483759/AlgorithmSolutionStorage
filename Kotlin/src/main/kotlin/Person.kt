
data class Person(private val name: String, val age: Int, var isMarried: Boolean = false) {
    companion object {
        fun who() = "I'm $this.name and $this.age old"
    }

    override fun equals(other: Any?): Boolean =
        (other is Person)
            && name == other.name
            && age == other.age
}