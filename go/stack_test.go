package main

import "testing"

func TestNewStack(t *testing.T) {
	if stack := NewStack(50); stack == nil {
		t.Fatal("NewStack must not return a nil pointer!")
	}
}

func TestStack_Peek(t *testing.T) {
	stack := NewStack(50)
	if p := stack.Peek(); p != 0 {
		t.Fatal("Expecting 0 due to stack underflow!")
	}

	stack.Push(4)
	if p := stack.Peek(); p!= 4 {
		t.Fatalf("Expecting 4, got %d", p)
	}
}

func TestStack_Pop(t *testing.T) {
	stack := NewStack(50)
	if p := stack.Pop(); p != 0 {
		t.Fatal("Expecting 0 due to stack underflow!")
	}

	stack.Push(4)
	p := stack.Pop()

	if p != 4 {
		t.Fatalf("Expecting popped element to be 4, got %d", p)
	}

	if stack.Top != -1 {
		t.Fatalf("Expecting top to be -1, but got %d", p)
	}
}

func TestStack_Push(t *testing.T) {
	stack := NewStack(50)
	stack.Push(4)

	if p := stack.Items[stack.Top]; p != 4 {
		t.Fatalf("Expecting top element to be 4, but got %d", p)
	}

	stack.Pop()

	for i := 0; i < stack.Size; i++ {
		stack.Push(i)
	}

	if stack.Push(4) {
		t.Fatalf("Push should've returned false due to stack overflow!")
	}
}
