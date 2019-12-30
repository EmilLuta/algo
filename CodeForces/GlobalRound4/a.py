n = int(input())
a = [int(i) for i in input().split(' ')]
k = [1]
check = a[0] // 2
f = a[0]
against = 0
for i in range(1, n):
    if a[i] <= check:
        k.append(i + 1)
        f += a[i]
    else:
        against += a[i]

if f > against:
    print(len(k))
    print(*k)
else:
    print(0)
