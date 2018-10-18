def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    a.sort(reverse=True)
    c = 0
    i = 0
    while sum(a[i:]) >= c:
        c += a[i]
        i += 1
    return i

print(go())
