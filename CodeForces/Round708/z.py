from collections import defaultdict

def decompose(n):
    d = defaultdict(int)
    x = 2
    while n >= x:
        d[x] += 1
        n /= x
    print(d)

decompose(2097152)

