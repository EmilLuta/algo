# Given a sequence of N numbers (N <= 10^5) and Q (Q <= 10^5) queries, each with L, R (0 <= L <= R <= n - 1), where you must print the sum of elements in [L, R]

# n, q = [int(i) for i in input().split(' ')]
# a = [int(i) for i in input().split(' ')]

# pre = [0]
# for i in range(n):
#     pre.append(pre[i] + a[i])
# print(pre)

# for _ in range(q):
#     l, r = [int(i) for i in input().split(' ')]
#     print(pre[r + 1] - pre[l])

# Check if there is an interval with XOR being 0.

#####
# 1 #
#####

# n = int(input())
# a = [int(i) for i in input().split(' ')]

# pre = [0]
# for i in range(n):
#     pre.append(pre[i] ^ a[i])

# pre.sort()

# for i in range(n):
#     if pre[i] == pre[i + 1]:
#         print('Yup')

#####
# 2 #
#####

n = int(input())
a = [int(i) for i in input().split(' ')]

pre = [0]
for i in range(n):
    pre.append(pre[i] ^ a[i])

intervals = 0
d = {}

for i in range(n):
    if pre[i] in d:
        d[pre[i]] += 1
        intervals += d[pre[i]]
    else:
        d[pre[i]] = 1

print("There are {} intervals with XOR equal".format(intervals))
