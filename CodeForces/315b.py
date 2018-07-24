def go():
    n, m = (int(i) for i in input().split(' '))
    a = [int(i) for i in input().split(' ')]
    keep = 0
    o = ''
    for i in range(m):
        data = tuple(int(i) for i in input().split(' '))
        if data[0] == 1:
            a[data[1] - 1] = data[2] - keep
        elif data[0] == 2:
            keep += data[1]
        elif data[0] == 3:
            o += '{}\n'.format(a[data[1] - 1] + keep)
    return o

print(go())
