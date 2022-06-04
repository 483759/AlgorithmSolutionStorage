
val people = listOf(Person("Alice", 29), Person("Bob", 31))

fun main(args: Array<String>) {
    println(people.filter { it.age < 30 })       // Collection 라이브러리의 filter 메서드 사용

    people.asSequence()
        .filter { it.age < 30 }

    val result = mutableListOf<Person>()
    for (person in people) {
        if (person.age < 30) result.add(person)
    }
}