n = int(input())
a = [int(i) for i in input().split(' ')]
b = [int(i) for i in input().split(' ')]
dp = [a[0], b[0], 0]
for i in range(1, n):
    dp = max(dp[1], dp[2]) + a[i],  max(dp[0], dp[2]) + b[i], max(dp[0], dp[1])
print(max(dp))
