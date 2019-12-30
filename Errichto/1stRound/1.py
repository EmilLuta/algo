# Given a sequence of N numbers (N ≤ 10^5, -10^9 <= a[i] <= 10^9), check if there is an interval with sum of elements equal to 0

#####
# 1 #
#####

# n = int(input())
# a = [int(i) for i in input().split(' ')]

# dp = []

# for i in range(n):
#     dp.append([None for _ in range(n)])

# for i in range(n):
#     dp[i][i] = a[i]
#     for j in range(i + 1, n):
#         dp[i][j] = dp[i][j - 1] + a[j]
#         if dp[i][j] == 0:
#             print('Found it on interval {} - {}'.format(i, j))

#####
# 2 #
#####

# n = int(input())
# a = [int(i) for i in input().split(' ')]

# for i in range(n):
#     s = 0
#     for j in range(i, n):
#         s += a[j]
#         if s == 0:
#             print('Found it on interval {} - {}'.format(i, j))

#####
# 3 #
# a #
#####

# n = int(input())
# a = [int(i) for i in input().split(' ')]

# pre = [0]
# for i in range(n):
#     pre.append(pre[i] + a[i])

# pre.sort()

# for i in range(n):
#     if pre[i] == pre[i + 1]:
#         print('FOUND')

#####
# 3 #
# b #
#####

# n = int(input())
# a = [int(i) for i in input().split(' ')]

# pre = [0]
# for i in range(n):
#     pre.append(pre[i] + a[i])

# d = {}


# for i in range(n + 1):
#     if pre[i] in d:
#         print('Found it on interval {} - {}'.format(i - 1, d[pre[i]]))
#     else:
#         d[pre[i]] = i

#####
# 4 #
#####

n = int(input())
a = [int(i) for i in input().split(' ')]

d = {}

sum_so_far = 0
for i in range(n + 1):
    if i >= 1:
        sum_so_far += a[i - 1]
    if sum_so_far in d:
        print('Found it on interval {} - {}'.format(i - 1, d[sum_so_far]))
    else:
        d[sum_so_far] = i
