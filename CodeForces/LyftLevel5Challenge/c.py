def go():
    C = 1000000000
    n, m = [int(i) for i in input().split(' ')]
    k = []
    h = 0
    o = 0
    too_many = False
    for i in range(n):
        k.append(int(input()))
    len_k = len(k)
    for i in range(m):
        x1, x2, y = [int(i) for i in input().split(' ')]
        if x1 == 1 and x2 == C:
            v += 1
        for i in k:
            if x1 <= i <= x2 and x1 == 1:
                k[i] += 1
    if len_k == 0:
        return v
    k = sorted(k.values(), reverse=True)
    k.append(v)
    o = 0
    x = k[0]
    for i in range(len_k + 1):
        x = min(i + k[i], x)
    return x

print(go())
