# Given an sequence of positive numbers, find the sum of gcd's of all intervals


############
# 1 PREFIX #
############

n, q = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

pre = [0] * (n + 1)

for i in range(n):
    pre[i + 1] = a[i] + pre[i]

for _ in range(q):
    _, l, s = [int(i) for i in input().split(' ')]
    low = l
    high = n
    while low < high:
        mid = (high + low) // 2
        if s <= pre[mid + 1] - pre[l]:
            high = mid
        else:
            low = mid + 1
    print(high)

###########
# 2 TREES #
###########

base = 1
while base < n:
    base *= 2

t = [None] * (base * 2)

for i in range(n):
    t[base + i] = a[i]


