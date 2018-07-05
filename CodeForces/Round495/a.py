def go():
    n, d = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    if n == 1:
        return 2
    total = 2
    for i in range(0, n - 1):
        if a[i] + d == a[i + 1] - d:
            total += 1
        elif a[i] + d < a[i + 1] - d:
            total += 2
    return total

print(go())
