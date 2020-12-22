from collections import defaultdict
from itertools import permutations

for N in range(8):

    def get_graph(perm):
        global N
        graph = defaultdict(list)
        for i in range(N):
            for j in range(i - 1, -1, -1):
                if perm[j] > perm[i]:
                    graph[i].append(j)
                    graph[j].append(i)
                    break
            for j in range(i + 1, N, 1):
                if perm[j] > perm[i]:
                    graph[i].append(j)
                    graph[j].append(i)
                    break
        return graph

    def has_cycle(graph):
        global N
        for i in range(N):
            queue = [i]
            index = 0
            seen = set()
            parents = {i: -1}
            while index < len(queue):
                node = queue[index]
                index += 1
                seen.add(node)
                for child in graph[node]:
                    parents[child] = node
                    if child != parents[node] and child in seen:
                        # import code
                        # code.interact(local=dict(globals(), **locals()))
                        return True
                    if child not in seen:
                        queue.append(child)
        return False

    with_cycle = without_cycle = 0

    all_perms = list(permutations(range(1, N + 1), N))

    for perm in all_perms:
        graph = get_graph(perm)
        cycle = has_cycle(graph)
        if cycle:
            with_cycle += 1
            # print(f'CYCLE: {perm}')
        else:
            without_cycle += 1
            # print(f'NO CYCLE: {perm}')
    print(f'N = {N}')
    print(f'with cycle {with_cycle}')
    print(f'without cycle {without_cycle}')

# print(has_cycle(get_graph([1, 2, 3, 4, 5])))
