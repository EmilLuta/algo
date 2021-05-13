def go():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    m = 0
    for i in range(n):
        c = 0
        while i >= 0:
            i = a[i] - 1
            c += 1
        m = max(m, c)
    return m

print(go())
