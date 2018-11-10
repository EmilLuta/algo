def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    x = max(a)
    s1 = 0
    s2 = 0
    for i in range(n):
        s1 += a[i]
        s2 += x - a[i]
    if s2 > s1:
        return x
    while s1 >= s2:
        x += 1
        s2 += n
    return x

print(go())
