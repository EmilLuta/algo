n = int(input())
a = [int(i) for i in input().split(' ')]
s, f = [int(i) for i in input().split(' ')]

m = sum(a[i] for i in range(s - 1, f - 1))
current, time = m, 0
for i in range(n):
    current = current - a[(s - 1 + i) % n] + a[(f - 1 + i) % n]
    if current >= m:
        m = current
        time = i
print(n - time)
