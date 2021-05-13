n, d = [int(i) for i in input().split(' ')]
s = input()
dp = [float('inf')] * n
dp[0] = 0

for i in range(n):
    if s[i] == '1':
        for j in range(max(0, i - d), i):
            dp[i] = min(dp[i], dp[j] + 1)

if dp[n - 1] == float('inf'):
    print(-1)
else:
    print(dp[n - 1])
