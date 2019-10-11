from typing import List


class Stack:
    def __init__(self, size: int = 10):
        self.top: int = -1
        self.size: int = size
        self.items: List[int] = []

    def push(self, item: int) -> bool:
        if self.top >= (self.size - 1):
            print("Stack overflow!")
            return False
        self.top = self.top + 1
        self.items.insert(self.top, item)
        print(f"{item} pushed into the stack")
        return True

    def pop(self) -> int:
        if self.top < 0:
            print("Stack underflow!")
            return 0
        item: int = self.items[self.top]
        self.top = self.top - 1
        return item

    def peek(self) -> int:
        if self.top < 0:
            print("Stack underflow!")
            return 0
        return self.items[self.top]
