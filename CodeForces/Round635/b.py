t = int(input())
out = ''
while t > 0:
    t -= 1
    x, n, m = [int(i) for i in input().split(' ')]
    if x <= m * 10:
        out += 'YES\n'
        continue
    while x > 20 and n > 0:
        x //= 2
        x += 10
        n -= 1
    for i in range(m):
        x -= 10
    if x <= 0:
        out += 'YES\n'
        continue
    out += 'NO\n'
print(out)
