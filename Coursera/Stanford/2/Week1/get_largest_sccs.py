import code
from collections import defaultdict

n = 875714


def load_data():
    graph = defaultdict(list)
    rev_graph = defaultdict(list)
    with open("input.txt", "r") as f:
        for line in f:
            x, y, *others = line.split(" ")
            x = int(x)
            y = int(y)
            graph[x].append(y)
            rev_graph[y].append(x)
    return graph, rev_graph


# graph, rev_graph = load_data()
rev_graph = {
    1: [7],
    7: [4, 9],
    4: [1],
    9: [6],
    6: [8, 3],
    3: [9],
    8: [2],
    2: [5],
    5: [8],
}
n = 9
f = [None] * (n + 1)
t = 0
visited = set()


def dfs_order(node):
    global t, visited, rev_graph
    stack = [node]
    found = False
    while stack:
        node = stack.pop()
        visited.add(node)
        found = False
        for child in rev_graph[node]:
            if child not in visited:
                stack.append(child)
                found = True
        t += 1
        if not found:
            f[node] = t
    # x = t
    # for i in range(len(keep) - 1, -1, -1):
        # code.interact(local=dict(globals(), **locals()))
        # f[keep[i]] = x
        # x -= 1


for i in range(n, 0, -1):
    if i not in visited:
        dfs_order(i)


code.interact(local=dict(globals(), **locals()))
