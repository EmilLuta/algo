n, k = map(int, input().split(' '))
m = []
for i in range(n):
    m.append([])
    for j in range(n):
        m[i].append(None)
if k == 1000:
    for i in range(n):
        for j in range(n):
            if m[i][j] is None:
                m[i][j] = 0
            if i == j:
                m[i][j] = 999
                m[i][(j + 1) % n] = 1
else:
    for i in range(n):
        for j in range(n):
            if i == j:
                m[i][j] = k
            else:
                m[i][j] = 0
for i in m:
    print(' '.join(str(z) for z in i))
