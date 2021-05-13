def go():
    n, m = [int(i) for i in input().split(' ')]
    x = [0] * (m + 1)
    for i in range(n):
        a = [int(i) for i in input().split(' ')]
        for i in range(a[0], a[1] + 1):
            x[i] = 1
    o = ''
    c = 0
    for i in range(1, len(x)):
        if x[i] == 0:
            o += '{} '.format(i)
            c += 1
    print(c)
    return o.strip()
print(go())
