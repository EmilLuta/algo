# Product of all other elements
n, q = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

prefix = [1] * n
suffix = [1] * n

for i in range(n - 1):
    prefix[i + 1] = a[i] * prefix[i]
    suffix[n - i - 2] = a[n - i - 1] * suffix[n - i - 1]

for _ in range(q):
    i = int(input())
    print(prefix[i] * suffix[i])
