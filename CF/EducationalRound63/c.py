from math import gcd

def go():
    n, m = map(int, input().split(' '))
    x = [int(i) for i in input().split(' ')]
    p = [int(i) for i in input().split(' ')]
    diffs = set()
    start = x[0]
    for i in range(1, n):
        diffs.add(x[i] - x[i - 1])
    d = list(sorted(diffs))
    g = d[0]
    for i in range(1, len(d)):
        g = gcd(g, d[i])
    for i in range(m):
        if g % p[i] == 0:
            return "YES\n{} {}".format(start, i + 1)
    return "NO"

print(go())
