def solve():
    l, k = [int(i) for i in input().split(' ')]
    a = input()
    n = {
        'R': 'G',
        'G': 'B',
        'B': 'R',
    }
    x = 'R'
    y = 'G'
    z = 'B'
    prev_x = 'R'
    prev_y = 'G'
    prev_z = 'B'
    x_c = y_c = z_c = 0
    m = float('inf')
    for i in range(k):
        if a[i] != x:
            x_c += 1
        if a[i] != y:
            y_c += 1
        if a[i] != z:
            z_c += 1
        x = n[x]
        y = n[y]
        z = n[z]
    m = min(m, x_c, y_c, z_c)
    for i in range(k, l):
        if a[i - k] != prev_x:
            x_c -= 1
        if a[i - k] != prev_y:
            y_c -= 1
        if a[i - k] != prev_z:
            z_c -= 1
        if a[i] != x:
            x_c += 1
        if a[i] != y:
            y_c += 1
        if a[i] != z:
            z_c += 1
        prev_x = n[prev_x]
        prev_y = n[prev_y]
        prev_z = n[prev_z]
        x = n[x]
        y = n[y]
        z = n[z]
        m = min(m, x_c, y_c, z_c)
    return m

q = int(input())
o = ''
for _ in range(q):
    o += str(solve()) + '\n'
print(o)
