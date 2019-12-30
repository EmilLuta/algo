# DP 1

# n = int(input())
# dp = [1]
# for i in range(n):
#     c = input()
#     if c == "f":
#         dp.insert(0,0)
#     else:
#         for j in range(len(dp) - 2, -1, -1):
#             dp[j] = (dp[j] + dp[j + 1]) % 1000000007
#     print(dp)
# print(dp[0])

# DP 2

n = int(input())
dp = [1]
for i in range(n):
    c = input()
    if c == "f":
        dp.append(0)
    else:
        for j in range(1, len(dp)):
            dp[j] = (dp[j] + dp[j - 1]) % 1000000007
print(dp[-1])
