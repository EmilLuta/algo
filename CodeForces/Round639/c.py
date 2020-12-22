from math import log
t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    d = {}
    x = n * (int(log(n, 2)) + 1)
    for i in range(x):
        d[i + a[i % n]] = i
    if len(d) != x:
        out += 'NO\n'
    else:
        out += 'YES\n'
print(out)
