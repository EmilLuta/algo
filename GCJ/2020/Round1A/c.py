t = int(input())
out = ''
options = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def is_good(x, y, r, c):
    return x >= 0 and x < r and y >= 0 and y < c

for tc in range(1, t + 1):
    r, c = [int(i) for i in input().split(' ')]
    matrix = []
    for i in range(r):
        matrix.append([int(i) for i in input().split(' ')])
    found = True
    total = 0
    for i in range(r):
        for j in range(c):
            if matrix[i][j] is not 0:
                total += matrix[i][j]
    while found:
        found = False
        to_delete = []
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    continue
                s = matrix[i][j]
                considered = 1
                for nx, ny in options:
                    x, y = i + nx, j + ny
                    if is_good(x, y, r, c) and matrix[x][y] != 0:
                        s += matrix[x][y]
                        considered += 1
                s /= considered
                if s > matrix[i][j]:
                    to_delete.append([i, j])
        if len(to_delete) > 0:
            found = True
            for x, y in to_delete:
                matrix[x][y] = 0
            for i in range(r):
                for j in range(c):
                    if matrix[i][j] is not 0:
                        total += matrix[i][j]
    out += f'Case #{tc}: {total}\n'
print(out)
