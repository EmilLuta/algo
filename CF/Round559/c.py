def go():
    n, m = map(int, input().split(' '))
    b = sorted([int(i) for i in input().split(' ')], reverse=True)
    g = sorted([int(i) for i in input().split(' ')])
    if b[0] > g[0]:
        return -1
    if m == 1:
        return -1
    total = 0
    for i in range(n):
        total += b[i] * m
    j = 0
    c = 0
    for i in range(m):
        if j >= n:
            return -1
        if c >= m - 1:
            j += 1
            c = 0
        if g[i] != b[j]:
            total += g[i] - b[j]
            c += 1
    return total

print(go())
