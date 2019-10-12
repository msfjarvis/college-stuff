def dectobin(num: int) -> str:
    numlist = list()
    while num != 0:
        numlist.append(str(num % 2))
        num = num // 2
    return "".join(numlist[::-1])


number = int(input("Input a decimal bumber "))
print("Binary of", number, "is", dectobin(number))
