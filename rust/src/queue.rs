pub struct Queue {
    front: usize,
    rear: usize,
    size: usize,
    pub capacity: usize,
    queue: [i32; 10 /* capacity */],
}

impl Default for Queue {
    fn default() -> Queue {
        Queue {
            front: 0,
            rear: 10 /* capacity */ - 1,
            size: 0,
            capacity: 10,
            queue: [-1; 10 /* capacity */],
        }
    }
}

impl Queue {
    pub fn enqueue(&mut self, item: i32) {
        if self.is_full() {
            return;
        }
        self.rear = (self.rear + 1) % self.capacity;
        self.queue[self.rear] = item;
        self.size += 1;
        println!("Successfully enqueued {}", item);
    }

    pub fn dequeue(&mut self) -> i32 {
        if self.is_empty() {
            return std::i32::MIN;
        }
        let item = self.queue[self.front];
        self.front = (self.front + 1) % self.capacity;
        self.size -= 1;
        item
    }

    pub fn front(&self) -> i32 {
        if self.is_empty() {
            return std::i32::MIN;
        }
        self.queue[self.front]
    }

    pub fn rear(&self) -> i32 {
        if self.is_empty() {
            return std::i32::MIN;
        }
        self.queue[self.rear]
    }

    pub fn is_full(&self) -> bool {
        self.size == self.capacity
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }
}
