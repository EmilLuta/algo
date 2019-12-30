def go():
    n, m = map(int, input().split(' '))
    a = []
    b = []
    for l in [a, b]:
        for i in range(n):
            l.append([int(i) for i in input().split(' ')])
    if a[0][0] != b[0][0] or a[-1][-1] != b[-1][-1]:
        return "NO"
    counter_a = {}
    counter_b = {}
    for l, c in [(a, counter_a), (b, counter_b)]:
        for i in range(n):
            for j in range(m):
                c.setdefault(l[i][j], 0)
                c[l[i][j]] += 1
    if counter_a != counter_b:
        return "NO"
    return "YES"
print(go())
