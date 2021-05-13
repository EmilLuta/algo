def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    for i in range(n):
        if a[i] >= 0:
            a[i] = -a[i] - 1
    if n % 2 == 1:
        m = min(a)
        index = a.index(m)
        a[index] = -m - 1
    print(*a)

go()