def go():
    n, m = (int(i) for i in input().split(' '))
    f = list(sorted(int(i) for i in input().split(' ')))
    x = float('inf')
    for i in range(m - n + 1):
        x = min(x, f[i + n - 1] - f[i])
    return x
print(go())
