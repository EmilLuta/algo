def go():
    n, m, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    a.sort(reverse=True)
    m1 = a[0]
    m2 = a[1]
    x = m // (k + 1)
    return m1 * x * k + m2 * x + m % (k + 1) * m1

print(go())
