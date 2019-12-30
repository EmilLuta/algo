# Implementation: read a grid for tick-tack-toe and say whether someone already won

matrix = []

n = 3

for i in range(n):
    a = [i for i in input()]
    matrix.append(a)

for i in range(n):
    if len(set([matrix[i][j]  for j in range(n)])) == 1 and matrix[i][0] != '.':
        print('{} wins'.format(matrix[i][0]))
    if len(set([matrix[j][i]  for j in range(n)])) == 1 and matrix[0][i] != '.':
        print('{} wins'.format(matrix[0][i]))
    v1.add(matrix[i][i])
    v2.add(matrix[i][n - i - 1])
if len(v1) == 1 and matrix[0][0] != '.':
    print('{} wins'.format(matrix[0][0]))

if len(v1) == 1 and matrix[0][2] != '.':
    print('{} wins'.format(matrix[0][2]))

