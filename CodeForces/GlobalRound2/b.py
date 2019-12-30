# def go():
#     n, k = map(int, input().split(' '))
#     a = [int(i) for i in input().split(' ')]
#     dp = []
#     for i in range(n):
#         dp.append([0, 0])
#     dp[0] = [a[0], a[0]]
#     dp[1] = [a[0] + a[1], max(a[0], a[1])]
#     i = 2
#     while i < n:
#         dp[i][0] = min(dp[i - 1]) + a[i]
#         dp[i][1] = min(dp[i - 2]) + max(a[i - 1], a[i])
#         if dp[i][0] > k and dp[i][1] > k:
#             return i
#         i += 1
#     return n
# print(go())
