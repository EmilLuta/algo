n = int(input())
a = [int(i) for i in input().split(' ')]
s, f = [int(i) for i in input().split(' ')]

gap = f - s

for i in range(n):
    a.append(a[i])

pre = [0] * (n * 2)
m = 0
index = -1

for i in range(n * 2):
    pre[i] = pre[i - 1] + a[i]

for i in range(n * 2 - gap):
    if (pre[i + gap] - pre[i] >= m):# or (pre[i] - pre[i - (f - s)] == m and i % n < index):
        m = pre[i + gap] - pre[i]
        index = (s - i) % n
print(index)
