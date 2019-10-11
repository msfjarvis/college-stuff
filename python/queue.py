from typing import List
import sys


class Queue:
    def __init__(self, capacity: int = 10):
        self.front = 0
        self.rear = capacity - 1
        self.size = 0
        self.capacity = capacity
        self.items: List[int] = []

    def enqueue(self, item: int):
        if self.is_full():
            return
        self.rear = (self.rear + 1) % self.capacity
        self.items[self.rear] = item
        self.size = self.size + 1
        print(f"Successfully enqueued {item}")

    def dequeue(self) -> int:
        if self.is_empty():
            return -sys.maxint - 1
        item: int = self.items[self.front]
        self.front = (self.front + 1) % self.capacity
        self.size = self.size - 1
        return item

    def rear(self) -> int:
        if self.is_empty():
            return -sys.maxint - 1
        return self.items[self.rear]

    def front(self) -> int:
        if self.is_empty():
            return -sys.maxint - 1
        return self.items[self.front]

    def is_full(self) -> bool:
        return self.size == self.capacity

    def is_empty(self) -> bool:
        return self.size == 0
