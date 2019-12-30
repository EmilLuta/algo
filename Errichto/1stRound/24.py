"""
1. Implement slow solution n * A * A
2. Implement fast solution n * A
3. Also, implement a recursive exponential solution that prints all valid sequences b[].
4. Solve CF candies problem (boys and girls).

Problem G. Increasing Sequences
You are given a sequence A of n positive integers a[1], . . . , a[n].
Find the number of different strictly increasing sequences of
positive integers b[1] < b[2] < . . . < b[n] that one can obtain by
decreasing some (possibly none) elements of sequence A, i.e.
b[i] ≤ a[i] for all i. As the answer may be large, print it modulo
10^9 + 7.

Input
The first line contains one integer n (1 ≤ n ≤ 100). The
second line contains n integers a[1], . . . , a[n] (1 ≤ a[i] ≤ 10000).

Output
Print the answer modulo 10^9 + 7.

Example input
3
3 2 4

Example output
2

Explanation: Sequences 1, 2, 3 and 1, 2, 4 fulfill conditions for the example.
"""

#####
# 1 #
#####
n = 3 #int(input())
a = [3, 3, 4] # [int(i) for i in input().split(' ')]

dp = []
max_a = max(a)
for i in range(n):
    dp.append([0 for _ in range(max_a + 1)])

# dp[i][j] - the number of increasing sequences until i that have value j on position i



for i in range(1, a[0] + 1):
    dp[0][i] = 1


for i in range(1, n):
    sum_dp = [0] * (max_a + 1)
    for j in range(1, max_a + 1):
        sum_dp[j] = dp[i - 1][j] + sum_dp[j - 1]
    for j in range(1, a[i] + 1):
        dp[i][j] = sum_dp[j - 1]  # sum(dp[i - 1][:j])
print(dp)
print(sum(dp[-1]))
