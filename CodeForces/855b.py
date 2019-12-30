n, p, q, r = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]
m_inf = float('-inf')
dp = []
for i in range(n + 1):
    dp.append([m_inf, m_inf, m_inf])

for i in range(1, n + 1):
    dp[i][0] = max(dp[i - 1][0], a[i - 1] * p)
    dp[i][1] = max(dp[i - 1][1], dp[i][0] + a[i - 1] * q)
    dp[i][2] = max(dp[i - 1][2], dp[i][1] + a[i - 1] * r)

print(dp[i][2])
