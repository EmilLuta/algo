from collections import defaultdict

def load_data():
    graph = defaultdict(list)
    with open('input.txt', 'r') as f:
        for line in f:
            line = line.strip()
            info = line.split('\t')
            node = int(info[0])
            for node_info in info[1:]:
                vertex, weight = [int(i) for i in node_info.split(',')]
                graph[node].append((vertex, weight))
                graph[vertex].append((node, weight))
    return graph

graph = load_data()
# graph = {
#     1: [(2, 1), (3, 4)],
#     2: [(1, 1), (3, 2), (4, 6)],
#     3: [(1, 4), (2, 2), (4, 3)],
#     4: [(2, 6), (3, 3)]
# }

costs = [1000000] * 201
costs[1] = 0

visited = set([1])
while len(visited) != len(graph):
    cheapest_node = None
    cheapest_weight = 1000000
    for node in visited:
        for child, weight in graph[node]:
            if child not in visited:
                current_weight = costs[node] + weight
                if current_weight < cheapest_weight:
                    cheapest_node = child
                    cheapest_weight = current_weight
    visited.add(cheapest_node)
    costs[cheapest_node] = cheapest_weight
import code
code.interact(local=dict(globals(), **locals()))
