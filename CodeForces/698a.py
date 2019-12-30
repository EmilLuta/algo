# DP 1

# n = int(input())
# a = [i for i in input().split(' ')]
# dp = []
# for i in range(n + 1):
#     dp.append([])
#     for _ in range(3):
#         dp[i].append(0)

# for i in range(1, n + 1):
#     dp[i][0] = max(dp[i - 1])
#     if a[i - 1] == '1' or a[i - 1] == '3':
#         dp[i][1] = max(dp[i - 1][0], dp[i - 1][2])
#         dp[i][1] += 1
#     else:
#         dp[i][1] = max(dp[i - 1])
#     if a[i - 1] == '2' or a[i - 1] == '3':
#         dp[i][2] = max(dp[i - 1][0], dp[i - 1][1])
#         dp[i][2] += 1
#     else:
#         dp[i][2] = max(dp[i - 1])
# print(n - max(dp[n]))

# DP 2

n = int(input())
a = [i for i in input().split(' ')]
dp = []
for i in range(n):
    dp.append([])
    for _ in range(3):
        dp[i].append(0)

dp[0][0] = 1
if a[0] == '1' or a[0] == '3':
    dp[0][1] = 0
else:
    dp[0][1] = 1
if a[0] == '2' or a[0] == '3':
    dp[0][2] = 0
else:
    dp[0][2] = 1
for i in range(1, n):
    dp[i][0] = min(dp[i - 1]) + 1
    if a[i] == '1' or a[i] == '3':
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2])
    else:
        dp[i][1] = min(dp[i - 1]) + 1
    if a[i] == '2' or a[i] == '3':
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1])
    else:
        dp[i][2] = min(dp[i - 1]) + 1
print(min(dp[n - 1]))

