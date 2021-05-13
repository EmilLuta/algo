def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    a *= 2
    s = 0
    m = 0
    for i in range(len(a)):
        if a[i] == 0:
            s = 0
        s += a[i]
        m = max(m, s)
    return m

print(go())
