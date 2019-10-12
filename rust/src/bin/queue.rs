pub struct Queue {
    front_idx: usize,
    rear_idx: usize,
    size: usize,
    pub capacity: usize,
    queue: [i32; 10],
}

impl Default for Queue {
    fn default() -> Queue {
        Queue {
            front_idx: 0,
            rear_idx: 10 /* capacity */ - 1,
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
        self.rear_idx = (self.rear_idx + 1) % self.capacity;
        self.queue[self.rear_idx] = item;
        self.size += 1;
        println!("Successfully enqueued {}", item);
    }

    pub fn dequeue(&mut self) -> i32 {
        if self.is_empty() {
            return std::i32::MIN;
        }
        let item = self.queue[self.front_idx];
        self.front_idx = (self.front_idx + 1) % self.capacity;
        self.size -= 1;
        item
    }

    pub fn front(&self) -> i32 {
        if self.is_empty() {
            return std::i32::MIN;
        }
        self.queue[self.front_idx]
    }

    pub fn rear(&self) -> i32 {
        if self.is_empty() {
            return std::i32::MIN;
        }
        self.queue[self.rear_idx]
    }

    pub fn is_full(&self) -> bool {
        self.size == self.capacity
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }
}

fn main() {
    let mut queue = Queue::default();
    queue.enqueue(1);
    println!("front: {}", queue.front());
    println!("rear: {}", queue.rear());
    queue.enqueue(2);
    queue.dequeue();
    println!("front: {}", queue.front());
    println!("rear: {}", queue.rear());
    println!("Successfully dequeued {}", queue.dequeue());
}

#[cfg(test)]
mod tests {
    use super::Queue;
    use std::convert::TryInto;

    #[test]
    fn test_queue() {
        let mut queue = Queue::default();
        assert!(queue.is_empty());
        queue.enqueue(1);
        assert!(!queue.is_empty());
        queue.dequeue();
        assert!(queue.is_empty());
        for i in 0..queue.capacity {
            assert!(!queue.is_full());
            queue.enqueue(i.try_into().unwrap());
        }
        assert!(queue.is_full());
    }
}
