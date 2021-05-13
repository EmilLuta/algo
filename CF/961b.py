n, k = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]
t = [int(i) for i in input().split(' ')]

pre = [0] * (n + 1)

x = 0

for i in range(n):
    if t[i] == 1:
        x += a[i]
        a[i] = 0
    pre[i] = pre[i - 1] + a[i]

m = 0

for i in range(n - k + 1):
    m = max(m, pre[i + k - 1] - pre[i - 1])
print(m + x)
