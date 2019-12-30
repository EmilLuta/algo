"""
3) https://www.spoj.com/problems/ADAINDEX/, helpful drawings: https://www.webwhiteboard.com/board/6bdf3r4k
4) Hit https://codeforces.com/blog/entry/64250 - https://atcoder.jp/contests/dp/tasks
"""

#####
# 3 #
#####

n, q = map(int, input().split(' '))
t = {"children": {}, "value": 0}
for _ in range(n):
    word = input()
    t['value'] += 1
    current_node = t
    for l in word:
        current_node['children'].setdefault(l, {"children": {}, "value": 0})
        current_node['children'][l]['value'] += 1
        current_node = current_node['children'][l]
for _ in range(q):
    word = input()
    current_node = t
    printed = False
    for l in word:
        if l not in current_node['children']:
            print(0)
            printed = True
            break
        current_node = current_node['children'][l]
    if not printed:
        print(current_node['value'])

#####
# 4 #
#####

# 1

n = int(input())
a = [int(i) for i in input().split(' ')]

dp = [0] * n
dp[0] = 0
dp[1] = abs(a[0] - a[1])
for i in range(2, n):
    dp[i] = min(abs(a[i - 2] - a[i]) + dp[i - 2], abs(a[i - 1] - a[i]) + dp[i - 1])
print(dp[-1])

# 2

# n, k = map(int, input().split(' '))
# a = [int(i) for i in input().split(' ')]

# dp = [float('inf')] * n
# dp[0] = 0
# for i in range(1, n):
#     for x in range(1, min(i, k) + 1):
#         z = abs(a[i - x] - a[i]) + dp[i - x]
#         if dp[i] > z:
#             dp[i] = z
# print(dp[-1])

# n, k = map(int, input().split(' '))
# a = [int(i) for i in input().split(' ')]
# dp = [float('inf')] * n
# dp[0] = 0
# for i in range(n):
#     for j in range(i + 1, k +i + 1):
#         if j < n:
#             dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]))
# print(dp[-1])

# 3

# n = int(input())
# a = []
# b = []
# c = []
# dp = []
# for i in range(n):
#     dp.append([0, 0, 0])
# for i in range(n):
#     a_i, b_i, c_i = [int(i) for i in input().split(' ')]
#     a.append(a_i)
#     b.append(b_i)
#     c.append(c_i)

# dp[0][0] = a[0]
# dp[0][1] = b[0]
# dp[0][2] = c[0]
# for i in range(1, n):
#     dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i]
#     dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i]
#     dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i]

# print(max(dp[-1]))

# 4

n, w = map(int, input().split(' '))
dp = [0] * (w + 1)
for i in range(n):
    weight, value = map(int, input().split(' '))
    for weight_already in range(w - weight, -1, -1):
        dp[weight_already + weight] = max(dp[weight_already + weight], dp[weight_already] + value)
    
print(dp[-1])