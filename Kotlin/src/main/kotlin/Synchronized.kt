inline fun <T> synchronized(lock: Lock, action: () -> T) : T {
    lock.lock()
    return try {
        action()        // return 문이 필요한가?
    } finally {
        // lock.let { action }
        lock.unlock()
    }
}

fun foo(l: Lock) {
    println("Before sync")
    synchronized(l) {
        println("Action")
    }
    println("After sync")
}

class Lock {
    fun lock() = println("Locked!")
    fun unlock() = println("Unlocked!")
}

fun main() {
    foo(Lock())
}