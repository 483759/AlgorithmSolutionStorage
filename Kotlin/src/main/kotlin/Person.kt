class Person(val name: String, private var isMarried: Boolean)

// fun main() {
//     val binary = Person("binary.yun", false)
//     val clo = Person("clo.d")
//
//     println(person.isMarried)
// }

// data class Person(private val name: String, val age: Int, var isMarried: Boolean = false) {
//     override fun equals(other: Any?): Boolean =
//         (other is Person)
//             && name == other.name
//             && age == other.age
// }
//
// fun main() {
//     val p = Person("binary", 25)
//     println(p.age)
//
//     when(p) {
//         Person("binary", 25) -> print("Hi")
//         Person("yun", 30) -> print("Hello")
//         else -> print("World")
//     }
// }