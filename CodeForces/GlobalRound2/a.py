def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    d = {}
    for i in range(n):
        d.setdefault(a[i], [])
        d[a[i]].append(i)
    k = 0
    for i in d:
        for j in d:
            if i != j:
                k = max(k, abs(d[i][0] - d[j][-1]))
    return k

print(go())
