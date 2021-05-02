class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        answer = 0
        for i in range(0, n):
            for j in range(0, m):
                if matrix[i][j] == '1':
                    k = 1
                    good = True
                    answer = max(answer, k)
                    while i + k < n and j + k < m and matrix[i][j + k] == '1' and matrix[i + k][j] == '1' and good:
                        k += 1
                        for l in range(0, k):
                            if matrix[i + l][j + k - 1] != '1':
                                good = False
                            if matrix[i + k - 1][j + l] != '1':
                                good = False
                        if good:
                            answer = max(answer, k)
        return answer ** 2
