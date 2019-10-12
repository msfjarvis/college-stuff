def fibo(n: int) -> int:
    if n <= 1:
        return 1
    if n == 2:
        return 1
    return fibo(n-1) + fibo(n-2)


num = int(input("Enter number of fibonacci to print "))
for i in range(1, num+1):
    print(fibo(i))
