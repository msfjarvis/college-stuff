class Stack<T>{
    public var head:Int
    init {
        head = -1
    }
    val arr = ArrayList<T>()

    public fun push(item:T){
        arr?.add(item)
        head++
    }
    public fun peek(){
        if (head==-1) throw IndexOutOfBoundsException()
        println("${arr?.get(head)}")
    }
    public fun pop():T?{
        if (head==-1) throw IndexOutOfBoundsException()
        else{
            return arr?.get(head--)
        }
    }
}
fun main(){
    var stack:Stack<Int> = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.peek()
    stack.pop()
    stack.peek()
    stack.pop()
    stack.peek()
    stack.pop()
    stack.peek()
}