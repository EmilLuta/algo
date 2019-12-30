# HW: https://atcoder.jp/contests/dp/tasks/dp_d (and problems A, BC if you haven't already)
# HW: Think about the next problem (E). Reverse the meaning of value and weight.

######
# 1a #
######

# N, W = [int(i) for i in input().split(' ')]
# dp = [0] * (W + 1)

# for i in range(N):
#     w, v = [int(i) for i in input().split(' ')]
#     for weight in range(W, w - 1, -1):
#         dp[weight] = max(dp[weight], dp[weight - w] + v)
# print(max(dp))

######
# 1b #
######

N, W = [int(i) for i in input().split(' ')]
WEIGHT = 0
VALUE = 1
dp = []
a = []
for i in range(N + 1):
    dp.append([0] * (W + 1))
    if i != N:
        a.append([int(i) for i in input().split(' ')])

for weight in range(a[0][WEIGHT], W + 1):
    dp[0][weight] = a[0][VALUE]

for i in range(N):
    current_weight = a[i][WEIGHT]
    current_value = a[i][VALUE]
    import code
    code.interact(local=locals())
    for weight in range(current_weight, W + 1):
        dp[i + 1][weight] = max(dp[i + 1][weight], dp[i][weight - current_weight] + current_value)
print(dp)

#####
# 2 #
#####

# N, W = [int(i) for i in input().split(' ')]
# dp = [0] * (W + 1)

# for i in range(N):
#     w, v = 
