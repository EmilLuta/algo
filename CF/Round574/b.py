n, k = [int(i) for i in input().split(' ')]
i = 0
x = (i * (i + 1)) // 2
while x - (n - i) != k:
    i += 1
    x = (i * (i + 1)) // 2
print(n - i)
