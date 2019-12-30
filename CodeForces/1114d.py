n = int(input())
a = [int(i) for i in input().split(' ')]

dp = []
for i in range(n):
    dp.append([0] * 5000)

for i in range(1, n):
    for j in range(len(dp[0])):
        if j == a[i - 1] and j == a[i]:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = dp[i - 1][j] + 1
print(min(dp[-1]))
