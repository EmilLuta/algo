def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    m = 0
    for i in range(n):
        for j in range(i, n):
            c = 0
            for k in range(n):
                if i <= k and k <= j:
                    x = 1 - a[k]
                else:
                    x = a[k]
                if x == 1:
                    c += 1
            m = max(m, c)
    return m

print(go())
