def solve():
    n, k = [int(i) for i in input().split(' ')]
    a = input()
    x = 'RGB' * (k // 3 + 1)
    y = 'GBR' * (k // 3 + 1)
    z = 'BRG' * (k // 3 + 1)
    m = float('inf')
    for i in range(n - k + 1):
        x_c = y_c = z_c = 0
        for j in range(i, i + k):
            if a[j] != x[j - i]:
                x_c += 1
            if a[j] != y[j - i]:
                y_c += 1
            if a[j] != z[j - i]:
                z_c += 1
        m = min(m, x_c, y_c, z_c)
    return m

q = int(input())
o = ''
for _ in range(q):
    o += str(solve()) + '\n'
print(o)
