def go():
    n, a, b = [int(i) for i in input().split(' ')]
    x = [int(i) for i in input().split(' ')]
    total = 0
    for i in range(n // 2):
        if (x[i] == 1 and x[n - 1 - i] == 0) or (x[i] == 0 and x[n - 1 - i] == 1):
            return -1
        elif x[i] == 2 and x[i] == x[n - 1 - i]:
            total += 2 * min(a, b)
        elif x[i] == 2:
            if x[n - i - 1] == 1:
                total += b
            else:
                total += a
        elif x[n - i - 1] == 2:
            if x[i] == 1:
                total += b
            else:
                total += a
    if n % 2 == 1 and x[n // 2] == 2:
        total += min(a, b)
    return total

print(go())
