o = ''
t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted([int(i) for i in input().split(' ')])
    x = a.pop()
    y = a.pop()
    m = min(x, y)
    if len(a) < m:
        o += str(len(a)) + '\n'
    else:
        o += str(m - 1) + '\n'
print(o)
