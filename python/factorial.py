def facto(n: int) -> int:
    if n == 0:
        return 1
    return n * facto(n - 1)


num = int(input("Enter the number to find factorial of "))
print(f"{num}! = {facto(num)}")
