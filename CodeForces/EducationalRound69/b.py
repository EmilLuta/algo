from collections import defaultdict

n = int(input())
a = [int(i) for i in input().split(' ')]
m = 0
m_i = None
c = defaultdict(int)

for i in range(len(a)):
    if m < a[i]:
        m = a[i]
        m_i = i
    c[a[i]] += 1
if len(set(c.values())) != 1:
    print('NO')
    exit()
if next(iter(c.values())) != 1:
    print('NO')
    exit()
for i in range(1, m_i):
    if a[i] <= a[i - 1]:
        print('NO')
        exit()
for i in range(m_i + 1, n - 1):
    if a[i] <= a[i + 1]:
        print('NO')
        exit()
print('YES')
