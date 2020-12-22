'''
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
'''

class Solution:
    def numSquares(self, n: int) -> int:
        sqs = []
        i = 1
        while i * i <= n:
            sqs.append(i * i)
            i += 1
        c = 0
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for sq in sqs:
                if i < sq:
                    break
                dp[i] = min(dp[i], dp[i - sq] + 1)
        return dp[n]
