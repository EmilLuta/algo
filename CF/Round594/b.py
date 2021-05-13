n = int(input())
a = sorted([int(i) for i in input().split(' ')])
mid = n // 2
s_a = 0
s_b = 0
for i in range(mid):
    s_a += a[i]
for i in range(mid, n):
    s_b += a[i]
print(s_a * s_a + s_b * s_b)
