def solve():
    n = int(input())
    x_d = [-100000, 100000]
    y_d = [-100000, 100000]
    robots = []
    for i in range(n):
        robots.append([int(i) for i in input().split(' ')])
    for r in robots:
        x, y, l, u, r, d = r
        if l == 0:
            if x_d[1] < x:
                return '0'
            x_d[0] = max(x, x_d[0])
        if r == 0:
            if x_d[0] > x:
                return '0'
            x_d[1] = min(x, x_d[1])
        if d == 0:
            if y_d[1] < y:
                return '0'
            y_d[0] = max(y, y_d[0])
        if u == 0:
            if y_d[0] > y:
                return '0'
            y_d[1] = min(y, y_d[1])
    return ' '.join(str(i) for i in [1, x_d[0], y_d[0]])
q = int(input())
o = ''
for _ in range(q):
        o += solve() + '\n'
print(o)
