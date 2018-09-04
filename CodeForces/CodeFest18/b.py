def go():
    n, s = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    a.sort()
    x = 0
    for i in range(n // 2):
        x += max(0, a[i] - s)
        x += max(0, s - a[n - i - 1])
    x += abs(a[n // 2] - s)
    return x

print(go())
