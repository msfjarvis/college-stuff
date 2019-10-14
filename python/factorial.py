def facto(n: int) -> int:
    if n == 0:
        return 1
    return n * facto(n - 1)


def main():
    num = int(input("Enter a number to find factorial of "))
    print(f"{num}! = {facto(num)}")


if __name__ == "__main__":
    main()
