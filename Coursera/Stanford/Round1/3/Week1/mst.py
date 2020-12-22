from collections import defaultdict

def load_data():
    # return 4, {
        # 1: [[2, 1], [4, 3], [3, 4]],
        # 2: [[1, 1], [4, 2]],
        # 3: [[1, 4], [4, 5]],
        # 4: [[1, 3], [2, 2], [3, 5]],
    # }
    graph = defaultdict(list)
    with open('input_mst.txt', 'r') as f:
        a, b = [int(i) for i in next(f).split(' ')]
        for line in f:
            line = line.strip()
            v1, v2, w = line.split(' ')
            graph[int(v1)].append((int(v2), int(w)))
            graph[int(v2)].append((int(v1), int(w)))
    return a, graph

def mst():
    n, graph = load_data()
    seen = set([1])
    total = 0
    while len(seen) != n:
        min_child = None
        min_weight = float('inf')
        for node in seen:
            for child, weight in graph[node]:
                if child not in seen:
                    if min_weight > weight:
                        min_child = child
                        min_weight = weight
        seen.add(min_child)
        total += min_weight
    return total

print(mst())
