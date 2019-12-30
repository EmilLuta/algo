from math import ceil

t = int(input())
o = ''
for _ in range(t):
    a, b, c, d, k = [int(i) for i in input().split(' ')]
    pen = ceil(a / c)
    pencil = ceil(b / d)
    if pen + pencil <= k:
        o += f'{pen} {pencil}\n'
    else:
        o += '-1\n'
print(o)
