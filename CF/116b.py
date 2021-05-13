def look(a, i, j, m, n):
    if 0 <= i - 1 and n > i - 1 and a[i - 1][j] == 'P':
        a[i - 1][j] = 'X'
        return True
    if 0 <= i + 1 and n > i + 1 and a[i + 1][j] == 'P':
        a[i + 1][j] = 'X'
        return True
    if 0 <= j - 1 and m > j - 1 and a[i][j - 1] == 'P':
        a[i][j - 1] = 'X'
        return True
    if 0 <= j + 1 and m > j + 1 and a[i][j + 1] == 'P':
        a[i][j + 1] = 'X'
        return True
    return False

def go():
    n, m = (int(i) for i in input().split(' '))
    a = []
    total = 0
    for i in range(n):
        a.append(list(i for i in input()))
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'W':
                if look(a, i, j, m, n):
                    total += 1
    return total

print(go())
