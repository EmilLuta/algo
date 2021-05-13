def go():
    n, m = map(int, input().split(' '))
    m1 = []
    m2 = []
    for _ in range(n):
        m1.append([int(i) for i in input().split(' ')])
    for _ in range(n):
        m2.append([int(i) for i in input().split(' ')])
    modify_matrix(m1, m2, n, m)
    modify_matrix(m2, m1, n, m)
    if m1[n - 1][m - 1] <= m1[n - 1][m - 2]:
        m1[n - 1][m - 1], m2[n - 1][m - 1] = m2[n - 1][m - 1], m1[n - 1][m - 1]
        if m1[n - 1][m - 1] <= m1[n - 1][m - 2]:
            return False
    if m1[n - 1][m - 1] <= m1[n - 2][m - 1]:
        m1[n - 1][m - 1], m2[n - 1][m - 1] = m2[n - 1][m - 1], m1[n - 1][m - 1]
        if m1[n - 1][m - 1] <= m1[n - 2][m - 1]:
            return False

    if verify_matrix(m1, n, m) and verify_matrix(m2, n, m):
        return "Possible"
    return "Impossible"

def move(m1, m2, n, m, i, j):
    m1[i][j], m2[i][j] = m2[i][j], m1[i][j]
    if i > 0:
        if m1[i][j] <= m1[i - 1][j]:
            return False
        if m2[i][j] <= m1[i - 1][j]:
            return False
    if i < n - 1:
        if m1[i][j] >= m1[i + 1][j]:
            return False
        if m2[i][j] >= m2[i + 1][j]:
            return False
    if j != 0:
        if m1[i][j] <= m1[i][j - 1]:
            return False
        if m2[i][j] <= m2[i][j - 1]:
            return False
    if j < m - 1:
        if m1[i][j] >= m1[i][j + 1]:
            return False
        if m2[i][j] >= m2[i][j + 1]:
            return False
    return True

def modify_matrix(m1, m2, n, m):
    for i in range(n):
        for j in range(m - 1):
            if m1[i][j] >= m1[i][j + 1]:
                if move(m1, m2, n, m, i, j):
                    continue
                return "Impossible"
    for i in range(m):
        for j in range(n - 1):
            if m1[j][i] >= m1[j + 1][i]:
                if move(m1, m2, n, m, i, j):
                    continue
                return "Impossible"

def verify_matrix(a, n, m):
    maximum = 0
    for i in range(n):
        for j in range(1, m):
            if a[i][j] <= a[i][j - 1]:
                return False
    for i in range(m):
        for j in range(1, n):
            if a[j][i] <= a[j - 1][i]:
                return False
    return True
print(go())
