def go():
    n, k = [int(i) for i in input().split(' ')]
    a = [1] * k
    s = k
    for i in range(k):
        while(s + a[i] <= n):
            s += a[i]
            a[i] *= 2
    if s != n:
        return "NO"
    o = "YES\n"
    o += ' '.join(str(i) for i in a)
    return o
print(go())
