n = int(input())
a = [i[::-1] for i in input().split(' ')]
for i in a:
    d[a] = len(a)
total = 0
for i in range(n):
    for j in range(len(a[i])):
        x = (j + 1) * 2 - 1
        y = (j + 1) * 2 - 2
        total += n * int(a[i][j]) * (10 ** x)
        total += n * int(a[i][j]) * (10 ** y)
        total %= 998244353
print(total % 998244353)
