#[derive(Default)]
pub struct Stack {
    top: usize,
    items: [i32; 10],
}

impl Stack {
    pub fn push(&mut self, item: i32) {
        if self.top == 9 {
            println!("Overflow!");
            return;
        }
        self.items[self.top] = item;
        self.top += 1;
    }

    pub fn pop(&mut self) {
        if self.top == 0 {
            println!("Underflow!");
            return;
        }
        self.items[self.top] = 0;
        self.top -= 1;
    }

    pub fn peek(&self) -> i32 {
        self.items[self.top]
    }
}
