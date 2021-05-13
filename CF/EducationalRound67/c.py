def go():
    n, m = [int(i) for i in input().split(' ')]
    a = [10000] * (n + 1)
    x = [0] * (n + 1)
    queries = []
    for _ in range(m):
        t, l, r = [int(i) for i in input().split(' ')]
        if t == 1:
            for i in range(l + 1, r + 1):
                x[i] = 1
        else:
            queries.append((l + 1, r + 1))
    for q in queries:
        found = False
        for i in range(q[0], q[1]):
            if x[i] == 0:
                found = True
                break
        if not found:
            return 'NO'
    for i in range(1, n + 1):
        if x[i] == 0:
            a[i] = a[i - 1] - 1
        else:
            a[i] = a[i - 1] + 1
    return 'YES\n{}'.format(' '.join([str(a[i]) for i in range(1, n + 1)]))

print(go())
