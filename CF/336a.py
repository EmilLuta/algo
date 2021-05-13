a, b = map(int, input().split())
res = abs(a) + abs(b)
x, y = a // abs(a) * res, b // abs(b) * res
if x < 0:
    print(x, 0, 0, y)
else:
    print(0, y, x, 0)
