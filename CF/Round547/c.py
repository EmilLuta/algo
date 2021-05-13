def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    o = []
    s = set()
    for i in range(1, n - 1):
        x = a[i] - a[i - 1]
        o.append(x)
        s.add(x)
    # for i in range(1, n + 1):
    print(s)
    print(o)

print(go())
