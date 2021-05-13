def go():
    n, m = [int(i) for i in input().split(' ')]
    s_a = 0
    s_b = 0
    c = []
    for i in range(n):
        data = [int(i) for i in input().split(' ')]
        s_a += data[0]
        s_b += data[1]
        c.append(data[0] - data[1])
    if s_b > m:
        return -1

    x = s_a
    i = 0
    c = list(sorted(c, reverse=True))
    while x > m:
        x -= c[i]
        i += 1

    return i

print(go())
