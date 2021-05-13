from collections import defaultdict

n, k = [int(i) for i in input().split(' ')]
d = defaultdict(int)
for i in range(n):
    d[int(input())] += 1
drinks = (n + 1) // 2
total = 0
for i in d:
    x = d[i] // 2
    if d[i] // 2 <= drinks:
        total += x * 2
        drinks -= x
        d[i] -= x * 2
for i in d:
    if d[i] <= drinks:
        drinks -= d[i]
        total += d[i]
        d[i] = 0
print(total)
