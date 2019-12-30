def go():
    n, m, k = [int(i) for i in input().split(' ')]
    original = [int(i) for i in input().split(' ')]
    a = sorted(original, reverse=True)
    d = {}
    for i in range(m * k):
        d.setdefault(a[i], 0)
        d[a[i]] += 1
    c = 0
    r = 0
    o = []
    for i in range(n):
        if original[i] in d:
            if d[original[i]] == 1:
                d.pop(original[i])
            else:
                d[original[i]] -= 1
            c += 1
            if c == m:
                c = 0
                o.append(i + 1)
    total = sum(a[i] for i in range(m * k))
    return "{}\n{}".format(total, ' '.join(str(i) for i in o[:-1]))

print(go())
