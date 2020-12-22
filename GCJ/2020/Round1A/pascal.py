pascal = [[1], [1, 1]]
for i in range(2, 500):
    pascal.append([1])
    for j in range(1, len(pascal[-2])):
        pascal[-1].append(pascal[-2][j] + pascal[-2][j - 1])
    pascal[-1].append(1)

