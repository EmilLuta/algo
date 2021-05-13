from collections import defaultdict

t = int(input())
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    c = defaultdict(int)
    for i in range(n // 2):
        c[a[i] + a[n - i - 1]] += 1
    for s in sorted(
    out += f'{n // 2 - max(c.values())}\n'
print(out)
