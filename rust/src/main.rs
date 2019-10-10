mod stack;

use stack::Stack;

fn main() {
    let mut stack = Stack::default();
    stack.push(1);
    println!("{}", stack.peek());
    stack.pop();
    stack.pop();
}
