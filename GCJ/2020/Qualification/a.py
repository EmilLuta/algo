t = int(input())
tc = 1
while t > 0:
    t -= 1
    n = int(input())
    matrix = []
    for _ in range(n):
        matrix.append([int(i) for i in input().split(' ')])
    s = 0
    for i in range(n):
        s += matrix[i][i]
    x = 0
    y = 0
    for i in range(n):
        if len(set(matrix[i])) < n:
            x += 1
        if len(set(matrix[j][i] for j in range(n))) < n:
            y += 1
    print('Case #{}: {} {} {}'.format(tc, s, x, y))
    tc += 1
