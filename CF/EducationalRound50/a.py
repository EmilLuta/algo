def go():
    n, k = [int(i) for i in input().split(' ')]
    a, b = divmod(k, n)
    if b == 0:
        return a
    return a + 1

print(go())
