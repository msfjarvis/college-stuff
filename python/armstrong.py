def is_arm(num: int) -> bool:
    sumz = 0
    for i in str(num):
        sumz += int(i) ** len(str(num))
    return sumz == num
