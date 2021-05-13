def go():
    n, m = map(int, input().split(' '))
    m1 = []
    m2 = []
    max1 = max2 = 0
    for _ in range(n):
        m1.append([int(i) for i in input().split(' ')])
    for _ in range(n):
        m2.append([int(i) for i in input().split(' ')])
    for i in range(n):
        for j in range(m):
            m1[i][j], m2[i][j] = max(m1[i][j], m2[i][j]), min(m1[i][j], m2[i][j])
            max1 = max(max1, m1[i][j])
            max2 = max(max2, m2[i][j])
    if verify_matrix(m1, n, m) and verify_matrix(m2, n, m) and m1[n - 1][m - 1] == max1 and m2[n - 1][m - 1] == max2:
        return "Possible"
    return "Impossible"

def verify_matrix(a, n, m):
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
