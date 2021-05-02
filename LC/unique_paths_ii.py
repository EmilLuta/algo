from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid)
        if n == 0:
            return 0
        m = len(obstacleGrid[0])
        if m == 0:
            return
        dp = []
        for i in range(n):
            dp.append([0] * m)
        if obstacleGrid[0][0] != 1:
            dp[0][0] = 1
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 1:
                    continue
                positions = [(i, j - 1), (i - 1, j)]
                for pos in positions:
                    if pos[0] >= 0 and pos[1] >= 0 and obstacleGrid[pos[0]][pos[1]] != 1:
                        dp[i][j] += dp[pos[0]][pos[1]]
        return dp[n - 1][m - 1]

assert Solution().uniquePathsWithObstacles(
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]) == 2

assert Solution().uniquePathsWithObstacles([[1]]) == 0
