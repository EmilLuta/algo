t = int(input())

pascal = [[1], [1, 1]]
for i in range(2, 500):
    pascal.append([1])
    for j in range(1, len(pascal[-2])):
        pascal[-1].append(pascal[-2][j] + pascal[-2][j - 1])
    pascal[-1].append(1)

for tc in range(1, t + 1):
    n = int(input())
    q = [(0, 0)]
    index = 0
    parents = {(0, 0): 1}
    options = [(-1, -1), (-1, 0), (0, -1), (0, 1), (1, 0), (1, 1)]
    while index < len(q):
        node = q[index]
        index += 1
        for option in options:
            new_node = (node[0] + option[0], node[1] + option[1])
            if new_node not in parents and new_node[0] >= 0 and new_node[0] < 500 and new_node[1] >= 0 and new_node[1] < len(pascal[new_node[0]]):
                parents[new_node] = parents[node] + pascal[new_node[0]][new_node[1]]
                q.append(new_node)
    import code
    code.interact(local=dict(globals(), **locals()))
