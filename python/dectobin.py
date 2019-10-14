def dectobin(num: int) -> int:
    return int(bin(num)[2::])


def main():
    number = int(input("Enter a decimal number "))
    print("Binary of", number, "is", dectobin(number))


if __name__ == "__main__":
    main()
