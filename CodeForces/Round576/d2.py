n = int(input())
a = [int(i) for i in input().split(' ')]
q = int(input())
m = -1
k = {}
for _ in range(q):
    data = [int(i) for i in input().split(' ')]
    if data[0] == 2:
        for i in k:
            a[i] = k[i]
        m = max(m, data[1])
        k = {}
    else:
        k[data[1] - 1] = data[2]
for i in range(n):
    a[i] = max(a[i], m)
for i in k:
    a[i] = k[i]
print(' '.join(str(i) for i in a))

