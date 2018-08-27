def go():
    n, m = [int(i) for i in input().split(' ')]
    a = []
    for i in range(n):
        a.append([i for i in input()])
    start = None
    end = None
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'B':
                if start is None:
                    start = (i, j)
                end = (i, j)
                break
    x = (start[0] + 1 + end[0] + 1) // 2
    y = start[1] + x - start[0]
    return '{} {}'.format(x, y)

print(go())
