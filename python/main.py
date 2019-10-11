from stack import Stack


def main():
    stack = Stack(100)
    stack.push(1)
    print(stack.peek())
    stack.pop()
    stack.pop()
    for i in range(0, 101):
        stack.push(i)


if __name__ == "__main__":
    main()
