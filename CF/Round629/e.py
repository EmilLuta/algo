n, q = [int(i) for i in input().split(' ')]

g_min = []
g_max = []

tree = [[] for _ in range(n + 1)]
parents = [None for _ in range(n + 1)]
for i in range(n - 1):
    x, y = [int(i) for i in input().split(' ')]
    if x > y:
        g_max.append((x, y))
        g_min.append((y, x))
    else:
        g_min.append((x, y))
        g_max.append((y, x))
g_min.sort()
g_max.sort()
levels = [0 for _ in range(n + 1)]
queue = [1]
index = 0
while index < len(queue):
    node = queue[index]
    index += 1
    if len(tree[node]) != 0:

    # for child in graph[node]:
    #     if levels[child] == 0 and child != 1:
    #         parents[child] = node
    #         tree[node].append(child)
    #         levels[child] = levels[node] + 1
    #         queue.append(child)
out = ''
for i in range(q):
    data = input().split(' ')
    m_d = -1
    m_v = -1
    vertices = set()
    for i in range(1, len(data)):
        vertex = int(data[i])
        if levels[vertex] > m_d and vertex != 1:
            m_d = levels[vertex]
            m_v = vertex
        if vertex == 1:
            continue
        vertices.add(parents[vertex])
    node = m_v
    while node is not None:
        if node in vertices:
            vertices.remove(node)
        node = parents[node]
    if len(vertices) == 0:
        out += 'YES\n'
    else:
        out += 'NO\n'
print(out)
