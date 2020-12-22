from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        if m == 0:
            return 0
        dp = []
        for _ in range(n):
            dp.append([float('inf')] * m)
        dp[0][0] = grid[0][0]
        for i in range(n):
            for j in range(m):
                positions = [(i, j - 1), (i - 1, j)]
                for pos in positions:
                    x, y = pos[0], pos[1]
                    if x >= 0 and y >= 0:
                        dp[i][j] = min(dp[i][j], dp[x][y] + grid[i][j])
        return dp[n - 1][m - 1]

assert Solution().minPathSum([
  [1,3,1],
  [1,5,1],
  [4,2,1]
]) == 7
