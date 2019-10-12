use std::convert::TryInto;

pub struct Stack {
    top: i32,
    pub size: i32,
    items: [i32; 10],
}

impl Default for Stack {
    fn default() -> Stack {
        Stack {
            top: -1,
            size: 10,
            items: [0; 10],
        }
    }
}

impl Stack {
    pub fn push(&mut self, item: i32) -> bool {
        if self.top >= (self.size - 1) {
            println!("Stack overflow!");
            return false;
        }
        self.top += 1;
        self.items[Self::i32_to_usize(self.top)] = item;
        println!("{} pushed into stack", item);
        true
    }

    pub fn pop(&mut self) -> i32 {
        if self.top < 0 {
            println!("Stack underflow!");
            return 0;
        }
        let item = self.items[Self::i32_to_usize(self.top)];
        self.top -= 1;
        item
    }

    pub fn peek(&self) -> i32 {
        if self.top < 0 {
            println!("Stack underflow!");
            return 0;
        }
        self.items[Self::i32_to_usize(self.top)]
    }

    fn i32_to_usize(n: i32) -> usize {
        n.try_into().unwrap()
    }
}

fn main() {
    let mut stack = Stack::default();
    stack.push(1);
    println!("{}", stack.peek());
    stack.pop();
    stack.pop();
}

#[cfg(test)]
mod tests {
    use super::Stack;
    use std::convert::TryInto;

    #[test]
    fn test_stack() {
        let mut stack = Stack::default();
        stack.push(1);
        assert_eq!(stack.peek(), 1);
        println!("{} popped from stack", stack.pop());
        assert_ne!(stack.peek(), 1);
        for i in 0..stack.size {
            stack.push(i.try_into().unwrap());
        }
        assert_eq!(stack.peek(), stack.size - 1);
    }
}
