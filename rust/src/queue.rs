pub struct Queue {
    front: usize,
    rear: usize,
    capacity: usize,
    queue: [i32; 10],
}

impl Default for Queue {
    fn default() -> Queue {
        Queue {
            front: 0,
            rear: 0,
            capacity: 10,
            queue: [-1; 10],
        }
    }
}

impl Queue {
    pub fn dequeue(&mut self) {
        if self.front == self.rear {
            println!("Underflow!");
            return
        }
        self.queue[self.front] = -1;
        self.front -= 1;
    }

    pub fn enqueue(&mut self, item: i32) {
        if self.front == self.capacity - 1 {
            println!("Overflow!");
            return
        }
        self.queue[self.front + 1] = self.queue[self.front];
        for idx in 0..self.front {
            self.queue[idx + 1] = self.queue[idx];
        }
        self.queue[self.rear] = item;
        self.front += 1;
    }

    pub fn peek(&self) -> i32 {
        self.queue[self.front]
    }

    pub fn is_full(&self) -> bool {
        self.front == self.capacity - 1
    }

    pub fn is_empty(&self) -> bool {
        self.front == self.rear
    }
}
