from typing import List, Set, Tuple

class Solution:
    def __init__(self):
        self.explore_count = 0
        self.dfs_count = 0

    def is_valid(self, grid, n_r, n_c, n, m, visited):
        return 0 <= n_r and n_r < n and 0 <= n_c and n_c < m and grid[n_r][n_c] == "1" and (n_r, n_c) not in visited

    def dfs(self, grid, r, c, n, m, visited):
        self.dfs_count += 1
        visited.add((r, c))
        dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
        for p_r, p_c in dirs:
            n_r = r + p_r
            n_c = c + p_c
            if self.is_valid(grid, n_r, n_c, n, m, visited):
                self.dfs(grid, n_r, n_c, n, m, visited)

    def explore(self, grid: List[List[str]], s_r: int, s_c: int, n: int, m: int, visited: Set[Tuple[int, int]]) -> None:
        s = [(s_r, s_c)]
        visited.add((s_r, s_c))
        dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
        while len(s) != 0:
            self.explore_count += 1
            r, c = s.pop()
            for p_r, p_c in dirs:
                n_r = r + p_r
                n_c = c + p_c
                if self.is_valid(grid, n_r, n_c, n, m, visited):
                    s.append((n_r, n_c))
                    visited.add((n_r, n_c))

    def num_islands(self, grid: List[List[str]]) -> int:
        visited = set()
        n = len(grid)
        m = len(grid[0])
        islands = 0
        for r in range(n):
            for c in range(m):
                if grid[r][c] == "1" and (r, c) not in visited:
                    self.explore(grid, r, c, n, m, visited)
                    islands += 1
        return islands

    def num_islands_v2(self, grid: List[List[str]]) -> int:
        visited = set()
        n = len(grid)
        m = len(grid[0])
        islands = 0
        for r in range(n):
            for c in range(m):
                if grid[r][c] == "1" and (r, c) not in visited:
                    self.dfs(grid, r, c, n, m, visited)
                    islands += 1
        return islands
m = [
    ["1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","0","1","0","1","1"],
    ["0","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","0"],
    ["1","0","1","1","1","0","0","1","1","0","1","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","0","1","1","1","1","1","1","0","1","1","1","0","1","1","1","0","1","1","1"],
    ["0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","1","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","1","0","1","1","1","1","1","1","1","0","1","1","1","1","1","1"],
    ["1","0","1","1","1","1","1","0","1","1","1","0","1","1","1","1","0","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","0"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","0"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],
    ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
]
s = Solution()
s.num_islands(m)
s.num_islands_v2(m)
print(s.__dict__)