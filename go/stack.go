package main

import "fmt"

type Stack struct {
	Top   int
	Size  int
	Items []int
}

func NewStack(size int) *Stack {
	return &Stack{-1, size, []int{}}
}

func (s *Stack) Push(item int) bool {
	if s.Top >= s.Size-1 {
		fmt.Println("Stack overflow!")
		return false
	}
	s.Top = s.Top + 1
	s.Items = append(s.Items, item)
	fmt.Printf("%d pushed onto the stack\n", item)
	return true
}

func (s *Stack) Pop() int {
	var item = 0
	if s.Top < 0 {
		fmt.Println("Stack underflow!")
		return item
	}
	item, s.Items = s.Items[s.Top], s.Items[:s.Top]
	s.Top = s.Top - 1
	return item
}

func (s *Stack) Peek() int {
	if s.Top < 0 {
		fmt.Println("Stack underflow!")
		return 0
	}
	return s.Items[s.Top]
}
