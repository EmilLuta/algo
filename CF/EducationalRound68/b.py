def go():
    n, m = [int(i) for i in input().split(' ')]
    matrix = []
    line = []
    column = []
    for i in range(n):
        x = 0
        matrix.append([])
        for j in input():
            w = 0
            if j == '.':
                w = 1
                x += 1
            matrix[i].append(w)
        line.append(x)
    for j in range(m):
        x = 0
        for i in range(n):
            x += matrix[i][j]
        column.append(x)

    o = float('inf')
    for i in range(n):
        for j in range(m):
            x = line[i] + column[j]
            if matrix[i][j] == 1:
                x -= 1
            o = min(o, x)
    return o

o = ''
q = int(input())
for _ in range(q):
    o += f'{go()}\n'
print(o)
