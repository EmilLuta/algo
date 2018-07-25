def go():
    n, m = [int(i) for i in input().split(' ')]
    total = 0
    if n % 2 == 0:
        total += n // 2 * m
    elif m % 2 == 0:
        total += m // 2 * n
    else:
        total += n // 2 * m + m // 2
    return total

print(go())
