def bfs(graph, start, end):
    parents = {start: None}
    q = [start]
    index = 0
    while index < len(q):
        node = q[index]
        index += 1
        for child in graph[node]:
            if child not in parents:
                q.append(child)
                parents[child] = node
    out = set()
    node = end
    while node is not None:
        out.add(node)
        node = parents[node]
    return out

t = int(input())
p = ''
while t > 0:
    t -= 1
    n, m, first, second, third = [int(i) for i in input().split(' ')]
    first -= 1
    second -= 1
    third -= 1
    a = sorted([int(i) for i in input().split(' ')])
    graph = [[] for _ in range(n)]
    for i in range(m):
        x, y = [int(i) for i in input().split(' ')]
        x -= 1
        y -= 1
        graph[x].append(y)
        graph[y].append(x)
    path1 = bfs(graph, first, second)
    path2 = bfs(graph, second, third)
    same_path = len(path1 & path2) - 1
    path1_extra = len(path1) - same_path - 1
    path2_extra = len(path2) - same_path - 1
    s = 0
    for i in range(same_path):
        s += a[i] * 2
    for i in range(same_path, same_path + path1_extra + path2_extra):
        s += a[i]
    p += f'{s}\n'
print(p)
