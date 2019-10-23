def add(a, b):
    """Add Function"""
    return a + b


def subtract(a, b):
    """Subtract Function"""
    return a - b


def multiply(a, b):
    """Multiply Function"""
    return a * b


def divide(a, b):
    """Divide Function"""
    if b == 0:
        raise ValueError("Can not divide by zero!")
    return a / b


def facto(n: int) -> int:
    """Factorial Dunction"""
    if n == 0:
        return 1
    return n * facto(n - 1)


def main():
    print("Input 1 for Addition")
    print("Input 2 for Subtraction")
    print("Input 3 for Multiplication")
    print("Input 4 for Division")
    print("Input 5 for finding Factorial of a number")

    x = int(input("\nEnter the value of operation you want to do:-"))

    if x <= 0 or x > 5:
        print("Enter a valid option")
    else:

        if x == 1:
            print("You have selected Addition operation")
            a = int(input("Enter number 1:-"))
            b = int(input("Enter number 2:-"))
            print(add(a, b))

        if x == 2:
            print("You have selected Subtraction operation")
            a = int(input("Enter number 1:-"))
            b = int(input("Enter number 2:-"))
            print(subtract(a, b))

        if x == 3:
            print("You have selected Multiplication operation")
            a = int(input("Enter number 1:-"))
            b = int(input("Enter number 2:-"))
            print(multiply(a, b))

        if x == 4:
            print("You have selected Division operation")
            a = int(input("Enter number 1:-"))
            b = int(input("Enter number 2:-"))
            print(divide(a, b))

        if x == 5:
            num = int(input("Enter a number to find factorial of "))
            print(f"{num}! = {facto(num)}")


if __name__ == "__main__":
    main()
