def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    s = list(sorted(a))
    for i in range(n - 1):
        a[i + 1] += a[i]
        s[i + 1] += s[i]
    a = [0] + a
    s = [0] + s
    m = int(input())
    o = ''
    for i in range(m):
        data = [int(i) for i in input().split(' ')]
        if data[0] == 1:
            o += '{}\n'.format(a[data[2]] - a[data[1] - 1])
        else:
            o += '{}\n'.format(s[data[2]] - s[data[1] - 1])
    return o
print(go())
