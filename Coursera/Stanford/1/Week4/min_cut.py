import copy
import random

from math import log

def load_data():
    graph = {}
    with open('input.txt', 'r') as f:
        data = f.readlines()
        for row in data:
            row = row[:-2]
            node_data = [int(i) for i in row.split('\t')]
            graph[node_data[0]] = node_data[1:]
        return graph

def min_cut(graph, n):
    nodes = [i for i in range(1, n + 1)]
    while len(nodes) > 2:
        node1 = random.choice(nodes)
        node2 = random.choice(graph[node1])
        nodes.remove(node2)
        for node in graph[node2]:
            graph[node].remove(node2)
            if node == node1:
                continue
            graph[node].append(node1)
            graph[node1].append(node)
        graph.pop(node2)
    if len(graph[nodes[0]]) != len(graph[nodes[1]]):
        print("ce plm")
        import code
        code.interact(local=dict(globals(), **locals()))
    return len(graph[nodes[0]])

graph = load_data()
# graph = {1: [2, 3, 4], 2: [1, 4], 3: [1, 4], 4: [1, 2, 3]}
minimum = float('inf')
n = len(graph)
for i in range(n * n * (int(log(n)) + 1)):
    current = min_cut(copy.deepcopy(graph), n)
    minimum = min(minimum, current)
    print(f"Iteration: {i}, Current: {current}, Minimum: {minimum}")
print(minimum)
