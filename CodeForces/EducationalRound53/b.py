def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    c = {}
    o = []
    k = 0
    for i in range(n):
        c[a[i]] = i
    for i in range(n):
        x = c[b[i]]
        if x < k:
            o.append('0')
        else:
            o.append(str(c[b[i]] + 1 - k))
            k = c[b[i]] + 1
    return ' '.join(o)

print(go())
