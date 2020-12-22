from collections import defaultdict
import sys

sys.setrecursionlimit(20000)

n = 875714

def load_data():
    graph = defaultdict(list)
    rev_graph = defaultdict(list)
    with open('input.txt', 'r') as f:
        for line in f:
            x, y, *others = line.split(' ')
            x = int(x)
            y = int(y)
            graph[x].append(y)
            rev_graph[y].append(x)
    return graph, rev_graph
graph, rev_graph = load_data()

f = [None] * (n + 1)
t = 0
visited = set()

def dfs_order(node):
    global t, visited, rev_graph
    visited.add(node)
    for child in rev_graph[node]:
        if child not in visited:
            dfs_order(child)
    t += 1
    f[node] = t

for i in range(n, 0, -1):
    if i not in visited:
        dfs_order(i)


import code
code.interact(local=dict(globals(), **locals()))
