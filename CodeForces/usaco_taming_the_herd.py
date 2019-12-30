# http://usaco.org/index.php?page=viewproblem2&cpid=815
# with open('taming.in') as f:
    # x = f.read().split('\n')
    # n = int(x[0].strip())
    # a = [int(i) for i in x[1].strip().split(' ')]

n = int(input())
a = [int(i) for i in input().split(' ')]

#dp[day][# of breakouts][value of the current day] = min number of changes
inf = float('inf')
dp = []
for i in range(n):
    dp.append([])
    for j in range(n + 1):
        dp[i].append([])
        for k in range(n):
            dp[i][j].append(inf)

if a[0] == 0:
    dp[0][1][0] = 0
else:
    dp[0][1][0] = 1

for i in range(1, n):
    for j in range(1, n + 1):
        for k in range(n):
            if k == 0:

                for k2 in range(n):
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k2])
                if a[i] != k:
                    dp[i][j][k] += 1
            else:
                dp[i][j][k] = dp[i - 1][j][k - 1]
                if a[i] != k:
                    dp[i][j][k] += 1
            if dp[i][j][k] != inf:
                print("{} {} {}: {}".format(i + 1, j, k, dp[i][j][k]))

for i in range(n):
    print(dp[i])
for i in range(1, n + 1):
    print(min(dp[n-1][i]))

