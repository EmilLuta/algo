def go():
    s, n = [int(i) for i in input().split(' ')]
    a = []
    for i in range(n):
        x = [int(i) for i in input().split(' ')]
        a.append(x)
    a = sorted(a, key=lambda x: x[0])
    for i in a:
        if s > i[0]:
            s += i[1]
        else:
            return 'NO'
    return 'YES'

print(go())
