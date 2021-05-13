t = int(input())
out = ''
d = []
n = 9
d = [
    (0, 0), (3, 1), (6, 2),
    (1, 3), (4, 4), (7, 5),
    (2, 6), (5, 7), (8, 8),
]
while t > 0:
    t -= 1
    m = []
    for i in range(n):
        m.append([i for i in input()])
    for x, y in d:
        m[x][y] = '1' if m[x][y] != '1' else '2'
    for i in range(n):
        for j in range(n):
            out += m[i][j]
        out += '\n'
    out += '\n'
print(out)
