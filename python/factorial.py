def facto(n: int) -> int:
    if n == 0:
        return 1
    return n * facto(n - 1)
