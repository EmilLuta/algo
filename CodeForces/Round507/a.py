def go():
    n, a, b = [int(i) for i in input().split(' ')]
    x = [int(i) for i in input().split(' ')]
    total = 0
    for i in range(n // 2):
        if x[i] == x[n - i - 1] and x[i] != 2:
            continue
        elif x[i] == x[n - i - 1] and x[i] == 2:
            total += 2 * min(a, b)
        elif x[i] == 2:
            if x[n - i - 1] == 1:
                total += b
            else:
                total += a
        elif x[n - i - 1]:
            if x[i] == 1:
                total += b
            else:
                total += a
        else:
            return -1
    if n % 2 == 1 and x[n // 2 + 1] == 2:
        total += min(a, b)
    return total

print(go())
