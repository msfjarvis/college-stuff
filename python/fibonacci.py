def fibo(n: int) -> list:
    fin_lis = []
    if n <= 1:
        final_lis = [1]
    elif n == 2:
        final_lis = [1, 1]
    else:
        fin_lis = [1, 1]
        while len(fin_lis) != n:
            fin_lis.append(fin_lis[-1] + fin_lis[-2])
    return fin_lis


def main():
    num = int(input("Enter number of fibonacci to print "))
    print(fibo(num))


if __name__ == "__main__":
    main()
