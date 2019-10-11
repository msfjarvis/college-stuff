from stack import Stack
from queue import Queue


def main():
    stack = Stack(100)
    stack.push(1)
    print(stack.peek())
    stack.pop()
    stack.pop()
    for i in range(0, 101):
        stack.push(i)
    stack = None

    queue: Queue = Queue(100)
    queue.enqueue(1)
    print(f"front: {queue.front()}")
    print(f"rear: {queue.rear()}")
    queue.enqueue(2)
    queue.dequeue()
    print(f"front: {queue.front()}")
    print(f"rear: {queue.rear()}")
    print(f"Successfully dequeued {queue.dequeue()}")


if __name__ == "__main__":
    main()
