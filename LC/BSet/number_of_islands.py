class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        if m == 0:
            return 0
        visited = set()
        total = 0
        def count_islands(i, j):
            if i + 1 < n and i + 1 >= 0 and grid[i + 1][j] == '1' and (i + 1, j) not in visited:
                visited.add((i + 1, j))
                count_islands(i + 1, j)
            if i - 1 < n and i - 1 >= 0 and grid[i - 1][j] == '1' and (i - 1, j) not in visited:
                visited.add((i - 1, j))
                count_islands(i - 1, j)
            if j + 1 < m and j + 1 >= 0 and grid[i][j + 1] == '1' and (i, j + 1) not in visited:
                visited.add((i, j + 1))
                count_islands(i, j + 1)
            if j - 1 < m and j - 1 >= 0 and grid[i][j - 1] == '1' and (i, j - 1) not in visited:
                visited.add((i, j - 1))
                count_islands(i, j - 1)
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1' and (i, j) not in visited:
                    total += 1
                    visited.add((i, j))
                    count_islands(i, j)
        return total

print(Solution().numIslands([['1', '1', '1', '1', '0'], ['1', '1', '0', '1', '0'], ['1', '1', '0', '0','0'], ['0', '0', '0', '0', '0']]))
