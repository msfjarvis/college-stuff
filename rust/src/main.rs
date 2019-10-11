mod queue;
mod stack;

use stack::Stack;
use queue::Queue;

fn main() {
    let mut stack = Stack::default();
    stack.push(1);
    println!("{}", stack.peek());
    stack.pop();
    stack.pop();

    let mut queue = Queue::default();
    queue.enqueue(1);
    println!("{}", queue.peek());
    queue.dequeue();
    queue.dequeue();
}
