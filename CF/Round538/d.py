# def go():
#     n = int(input())
#     a = [int(i) for i in input().split(' ')]
#     d = {}
#     if n == 1:
#         return 0
#     d[a[0]] = 1
#     for i in range(1, n):
#         if a[i] == a[i - 1]:
#             continue
#         d.setdefault(a[i], 0)
#         d[a[i]] += 1
#     s = sum(d.values())
#     if len(d) == 1:
#         return 0
#     m = 0
#     for i in d:
#         if d[i] > m:
#             m = d[i]
#     return s - m

# print(go())

# n = int(input())
# a = [int(i) for i in input().split(' ')]

# INF = float('inf')

# dp = []
# for i in range(n):
#     dp.append([None] * n)
#     for j in range(n):
#         if j == i:
#             dp[i][j] = [0, 0]
#         else:
#             dp[i][j] = [INF, INF]

# for r in range(n):
#     for l in range(r, -1, -1):
#         for i in range(2):
#             c = a[l] if i == 0 else a[r]
#             if l > 0:
#                 dp[l - 1][r][0] = min(dp[l - 1][ r][0], dp[l][r][i] + int(c != a[l - 1]))

#             if r + 1 < n:
#                 dp[l][r + 1][1] = min(dp[l][r + 1][1], dp[l][r][i] + int(c != a[r + 1]))

# print(min(dp[0][n - 1][0], dp[0][n - 1][1]))
