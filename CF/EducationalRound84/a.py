from math import sqrt

t = int(input())

out = ''

while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    if n % 2 != k % 2:
        out += 'NO\n'
        continue
    if sqrt(n) < k:
        out += 'NO\n'
        continue
    out += 'YES\n'
print(out)
