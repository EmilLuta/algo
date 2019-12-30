from math import floor

n = int(input())
a = [float(input()) for _ in range(n)]
b = [floor(i) for i in a]
s = sum(b)
i = 0
while s != 0:
    if int(a[i]) != a[i]:
        b[i] += 1
        s += 1
    i += 1
print(*b, sep='\n')
