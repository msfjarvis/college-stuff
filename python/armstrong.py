def is_arm(num: int) -> bool:
    sumz = 0
    for i in str(num):
        sumz += int(i) ** len(str(num))
    return sumz == num


def main():
    number = int(input("Enter a number "))
    if is_arm(number):
        print(number, "is an armstrong number")


if __name__ == "__main__":
    main()
