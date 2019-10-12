def is_arm(num: int) -> bool:
    sumz = 0
    for i in str(num):
        sumz += int(i)**3
    return sumz == num


number = int(input("Enter a number "))
if is_arm(number):
    print(number, "is an armstrong number")
