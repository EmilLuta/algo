### BRUTE FORCE

# n, m = [int(i) for i in input().split(' ')]
# matrix = []
# for i in range(n):
#     matrix.append([j for j in input()])

# t = 0
# for x1 in range(n):
#     for y1 in range(m):
#         if matrix[x1][y1] == '0':
#             for x2 in range(x1, n):
#                 for y2 in range(y1, m):
#                     if matrix[x2][y2] == '0':
#                         cool = True
#                         p = 0
#                         # import code
#                         # code.interact(local=locals())
#                         for i in range(x1, x2 + 1):
#                             for j in range(y1, y2 + 1):
#                                 if matrix[i][j] == '1':
#                                     cool = False
#                                 p += 1
#                         if cool:
#                             t = max((x2 - x1 + 1) * 2 + (y2 - y1 + 1) * 2, t)

# print(t)

### DP (1)

# n, m = [int(i) for i in input().split(' ')]
# matrix = []
# for i in range(n):
#     matrix.append([j for j in input()])
# dp = []
# for i in range(n):
#     dp.append([])
#     for j in range(m):
#         dp[i].append([])
#         for k in range(n):
#             dp[i][j].append([])
#             for _ in range(m):
#                 dp[i][j][k].append(True)

# t = 0

# for x1 in range(n):
#     for y1 in range(m):
#         for x2 in range(x1, n):
#             for y2 in range(y1, m):
#                 dp[x1][y1][x2][y2] = dp[x1][y1][x2 - 1][y2] and dp[x1][y1][x2][y2 - 1] and matrix[x2][y2] != '1'
#                 if dp[x1][y1][x2][y2]:
#                     t = max((x2 - x1 + 1) * 2 + (y2 - y1 + 1) * 2, t)

# print(t)

### DP (2)

n, m = [int(i) for i in input().split(' ')]
matrix = []
far = []

t = 0

for i in range(n):
    matrix.append([j for j in input()])
    far.append([None for _ in range(m)])

for i in range(n):
    for j in reversed(range(m)):
        if matrix[i][j] == '1':
            far[i][j] = j - 1
        elif j == m - 1:
            far[i][j] = j
        else:
            far[i][j] = far[i][j + 1]

for i in range(n):
    for j in range(m):
        dist = float('inf')
        k = i
        while k < n and matrix[k][j] == '0':
            dist = min(dist, far[k][j])
            t = max(t, 2 * (k - i + dist - j + 2))
            k += 1

print(t)
