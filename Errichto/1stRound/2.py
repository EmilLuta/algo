# You are given a sequence of numbers (N ≤ 10^5) and queries (Q ≤ 10^5) about intervals. For each of given intervals L, R (1 ≤ L ≤ R ≤ N), say whether elements in this interval are increasing

#####
# 1 #
#####

# n, m = [int(i) for i in input().split(' ')]
# a = [int(i) for i in input().split(' ')]

# dp = []
# for i in range(n):
#     dp.append([True for _ in range(n)])

# for i in range(n):
#     for j in range(i + 1, n):
#         dp[i][j] = dp[i][j - 1] and a[j] > a[j - 1]

# for i in range(m):
#     l, r = [int(i) for i in input().split(' ')]
#     print(dp[l][r])

#####
# 2 #
#####

n, m = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

pre = [1]
for i in range(1, n):
    pre.append(pre[i - 1])
    if a[i] > a[i - 1]:
        pre[i] += 1

for i in range(m):
    l, r = [int(i) for i in input().split(' ')]
    if r - l == pre[r] - pre[l]:
        print('Yup')
    else:
        print('Nope')

# what if there are also queries that an element is changed?
# SEGMENT TREES
