# Biggest sum of subarray
n = int(input())
a = [int(i) for i in input().split(' ')]

m = 0
c = 0
for i in range(n):
    c += a[i]
    c = max(0, c)
    m = max(c, m)
print(m)