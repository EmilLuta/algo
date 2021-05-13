def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    k = min(a[n - 1], a[0]) // (n - 1)
    for i in range(1, n - 1):
        start = min(a[i], a[0]) // i
        end = min(a[i], a[n - 1]) // (n - i - 1)
        k = min(k, start, end)
    return k

print(go())
