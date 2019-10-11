mod queue;
mod stack;

use queue::Queue;
use stack::Stack;

fn main() {
    println!("Stack implementation");
    let mut stack = Stack::default();
    stack.push(1);
    println!("{}", stack.peek());
    stack.pop();
    stack.pop();

    println!("Queue implementation");
    let mut queue = Queue::default();
    queue.enqueue(1);
    assert!(!queue.is_empty());
    assert!(!queue.is_full());
    println!("{}", queue.peek());
    queue.dequeue();
    queue.dequeue();
    assert!(queue.is_empty());
    assert!(!queue.is_full());
}
