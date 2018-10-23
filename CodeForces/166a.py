def go():
    n, k = [int(i) for i in input().split(' ')]
    a = []
    for i in range(n):
        a.append([int(i) for i in input().split(' ')])
    a.sort(key=lambda x: (x[0], -x[1]), reverse=True)
    x = a[k - 1]
    i = k - 2
    j = k
    c = 1
    while i >= 0 and a[i] == x:
        c += 1
        i -= 1
    while j < n and a[j] == x:
        c += 1
        j += 1
    return c

print(go())
