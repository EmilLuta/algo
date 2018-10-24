def dfs(graph, node, visited, level, max_level):
    if level == max_level:
        if len(graph[node]) == 1:
            raise ValueError()
    if level == max_level + 1:
        if len(graph[node]) != 1:
            raise ValueError()
    for vertex in graph[node]:
        if vertex not in visited:
            visited.add(vertex)
            dfs(graph, vertex, visited, level + 1, max_level)

def go():
    n, k = [int(i) for i in input().split(' ')]
    graph = {}
    for i in range(n - 1):
        x, y = [int(i) for i in input().split(' ')]
        graph.setdefault(x, set())
        graph[x].add(y)
        graph.setdefault(y, set())
        graph[y].add(x)
    center = None
    for i in graph:
        if len(graph[i]) == 3:
            center = i
            break
    if center is None:
        return 'No'
    try:
        dfs(graph, center, set([center]), 1, k)
    except ValueError:
        return 'No'

    return 'Yes'



print(go())
