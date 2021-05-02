class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        visited = set()
        total = [0]
        def explore(i, j):
            sides = 4
            if i - 1 >= 0 and grid[i - 1][j] == 1:
                sides -= 1
                if (i - 1, j) not in visited:
                    visited.add((i - 1, j))
                    explore(i - 1, j)
            if i + 1 < n and grid[i + 1][j] == 1:
                sides -= 1
                if (i + 1, j) not in visited:
                    visited.add((i + 1, j))
                    explore(i + 1, j)
            if j - 1 >= 0 and grid[i][j - 1] == 1:
                sides -= 1
                if (i, j - 1) not in visited:
                    visited.add((i, j - 1))
                    explore(i, j - 1)
            if j + 1 < m and grid[i][j + 1] == 1:
                sides -= 1
                if (i, j + 1) not in visited:
                    visited.add((i, j + 1))
                    explore(i, j + 1)
            total[0] += sides
        if m == 0:
            return 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    visited.add((i, j))
                    explore(i, j)
                    return total[0]
print(Solution().islandPerimeter([[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]))
