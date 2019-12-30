n, k = [int(i) for i in input().split(' ')]

m = 10 ** 9 + 7
graph = {}
painted = {}
visited = []
dp = []
for i in range(n + 1):
    visited.append([False] * 4)
    dp.append([0] * 4)

for i in range(n - 1):
    a, b = [int(i) for i in input().split(' ')]
    graph.setdefault(a, [])
    graph.setdefault(b, [])
    graph[a].append(b)
    graph[b].append(a)

for i in range(k):
    a, b = [int(i) for i in input().split(' ')]
    painted[a] = b

def dfs(parent, at, color):
    if visited[at][color]:
        return
    visited[at][color] = True
    if at in painted and painted[at] != color:
        dp[at][color] = 0
        return
    if color == 1:
        c1 = 2
        c2 = 3
    if color == 2:
        c1 = 1
        c2 = 3
    if color == 3:
        c1 = 1
        c2 = 2
    dp[at][color] = 1
    for i in graph[at]:
        if parent != i:
            dfs(at, i, c1)
            dfs(at, i, c2)
            dp[at][color] *= dp[i][c1] + dp[i][c2]
            dp[at][color] %= m

dfs(0, 1, 1)
dfs(0, 1, 2)
dfs(0, 1, 3)
print(sum(dp[1]) % m)
