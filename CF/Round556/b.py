n = int(input())
m = []
for i in range(n):
    m.append([i for i in input()])

for i in range(n):
    for j in range(n):
        if m[i][j] == '.':
            found = False
            if j + 2 < n and i - 1 > -1 and i + 1 < n:
                if m[i][j + 1] == '.' and m[i][j + 2] == '.' and m[i - 1][j + 1] == '.' and m[i + 1][j + 1] == '.':
                    m[i][j] = '#'
                    m[i][j + 1] = '#'
                    m[i][j + 2] = '#'
                    m[i - 1][j + 1] = '#'
                    m[i + 1][j + 1] = '#'
                    found = True
            if i + 2 < n and j - 1 > -1 and j + 1 < n:
                if m[i + 1][j] == '.' and m[i + 2][j] == '.' and m[i + 1][j - 1] == '.' and m[i + 1][j + 1] == '.':
                    m[i][j] = '#'
                    m[i + 1][j] = '#'
                    m[i + 2][j] = '#'
                    m[i + 1][j - 1] = '#'
                    m[i + 1][j + 1] = '#'
                    found = True
            if not found:
                print('NO')
                exit()
print('YES')
