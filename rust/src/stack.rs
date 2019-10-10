#[derive(Default)]
pub struct Stack {
    top: usize,
    items: [i32; 10],
}

impl Stack {
    pub fn push(&mut self, item: i32) {
        if self.top == 9 {
            println!("Overflow!")
        }
        self.items[self.top] = item;
        self.top += 1;
    }

    pub fn pop(&mut self) -> i32 {
        if self.top == 0 {
            println!("Underflow!")
        }
        let value = self.items[self.top];
        self.items[self.top] = 0;
        self.top -= 1;
        value
    }

    pub fn peek(&self) -> i32 {
        self.items[self.top]
    }
}
