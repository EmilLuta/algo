n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))

min_s = sum(a[:k])
min_i = 0
sums = [min_s]
for i in range(1, n - k + 1):
    x = sums[i - 1] - a[i - 1] + a[i + k - 1]
    sums.append(x)
    if x < min_s:
        min_s = x
        min_i = i
print(min_i + 1)
