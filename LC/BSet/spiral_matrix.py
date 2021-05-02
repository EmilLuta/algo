class Solution:
    def spiralOrder(self, matrix):
        output = []
        m = len(matrix)
        if m == 0:
            return output
        n = len(matrix[0])
        if n == 0:
            return output
        rows = min(n, m)
        m_rows = max(n, m)
        for i in range(rows // 2):
            for j in range(i, n - i):
                output.append(matrix[i][j])
            for j in range(i + 1, m - i - 1):
                output.append(matrix[j][n - i - 1])
            for j in range(n - i - 1, i - 1, -1):
                output.append(matrix[m - i - 1][j])
            for j in range(m - i - 2, i, -1):
                output.append(matrix[j][i])
        i = rows // 2
        if rows % 2 == 1:
            for j in range(i, m_rows - i):
                if n > m:
                    output.append(matrix[i][j])
                else:
                    output.append(matrix[j][i])
        return output
