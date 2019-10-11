package main

import "fmt"

func main() {
	stack := NewStack(100)
	stack.Push(1)
	fmt.Println(stack.Peek())
	stack.Pop()
	stack.Pop()

	for i := 0; i < 101; i++ {
		stack.Push(i)
	}
}
