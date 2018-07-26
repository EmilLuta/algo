def go():
    n, k = [int(i) for i in input().split(' ')]
    x = 0
    o = []
    for i in range(n, n - k, -1):
        o.append(str(i))
    o += [str(i) for i in range(1, n - k + 1)]
    return ' '.join(o)
print(go())
