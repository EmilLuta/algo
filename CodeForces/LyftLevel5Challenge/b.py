def go():
    n, m = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    o = []
    prev = None
    for i in range(n + m):
        if b[i] == 1:
            if prev is not None:
                c = 0
                p = 0
                for j in range(prev + 1, i):
                    if a[i] - a[j] < a[j] - a[prev]:
                        c += 1
                    else:
                        p += 1
                o[-1] += p
                o.append(c)
            else:
                o.append(i)
            prev = i
    if b[i] != 1:
        o[-1] += n + m - prev - 1
    return ' '.join(str(i) for i in o)

print(go())
