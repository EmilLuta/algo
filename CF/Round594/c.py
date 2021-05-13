# n = int(input())
# m = int(input())
n = 5
m = 5

def verify_color(matrix, i, j):
    options = [(-1, 0), (0, -1), (0, 1), (1, 0)]
    color = matrix[i][j]
    count = 0
    for option in options:
        x = i + option[0]
        y = j + option[1]
        if x > n - 1 or y > m - 1 or x < 0 or y < 0:
            continue
        if matrix[x][y] == color:
            count += 1
    if count > 1:
        return False
    return True

def verify(matrix):
    good = True
    for i in range(n):
        for j in range(m):
            good = good and verify_color(matrix, i, j)
    return good

matrices = []

for i0j0 in [True, False]:
    for i0j1 in [True, False]:
        for i0j2 in [True, False]:
            for i0j3 in [True, False]:
                for i0j4 in [True, False]:
                    for i1j0 in [True, False]:
                        for i1j1 in [True, False]:
                            for i1j2 in [True, False]:
                                for i1j3 in [True, False]:
                                    for i1j4 in [True, False]:
                                        for i2j0 in [True, False]:
                                            for i2j1 in [True, False]:
                                                for i2j2 in [True, False]:
                                                    for i2j3 in [True, False]:
                                                        for i2j4 in [True, False]:
                                                            for i3j0 in [True, False]:
                                                                for i3j1 in [True, False]:
                                                                    for i3j2 in [True, False]:
                                                                        for i3j3 in [True, False]:
                                                                            for i3j4 in [True, False]:
                                                                                for i4j0 in [True, False]:
                                                                                    for i4j1 in [True, False]:
                                                                                        for i4j2 in [True, False]:
                                                                                            for i4j3 in [True, False]:
                                                                                                for i4j4 in [True, False]:
                                                                                                    matrix = [[i0j0, i0j1, i0j2, i0j3, i0j4], [i1j0, i1j1, i1j2, i1j3, i1j4], [i2j0, i2j1, i2j2, i2j3, i2j4], [i3j0, i3j1, i3j2, i3j3, i3j4], [i4j0, i4j1, i4j2, i4j3, i4j4]]
                                                                                                    ok = verify(matrix)
                                                                                                    # import code
                                                                                                    # code.interact(local=dict(globals(), **locals()))
                                                                                                    if ok:
                                                                                                        matrices.append(matrix)

for matrix in matrices:
    for i in matrix:
        print(' '.join(str(x) for x in i))
    print('=========')
print(len(matrices))
