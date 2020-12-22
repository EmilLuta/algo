a = [4, 3, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2]
n = len(a)
k = 4
x = set()
for i in range(k, n):
    s = 0
    for i in range(i - k, i):
        s += a[i]
    x.add(s)
print(x)
