from collections import defaultdict

n, k = [int(i) for i in input().split(' ')]
graph = defaultdict(list)
for i in range(n - 1):
    x, y = [int(i) for i in input().split(' ')]
    graph[x].append(y)
    graph[y].append(x)

levels = {}

def dfs(node, parent):
    global graph, levels
    m = 0
    for child in graph[node]:
        if child == parent:
            continue
        m = max(m, dfs(child, node) + 1)
    levels[node] = m
    return m
dfs(1, 0)
cities = list(sorted([(value, key) for key, value in levels.items()]))
s = set()
for i in range(k):
    s.add(cities[i][1])
import code
code.interact(local=dict(globals(), **locals()))
levels = {}
if 1 in s:
    levels[1] = 0
else:
    levels = {1: 1}
queue = [1]
index = 0
answer = 0
while index < len(queue):
    node = queue[index]
    index += 1
    for child in graph[node]:
        if child not in levels:
            queue.append(child)
            levels[child] = levels[node]
            if child in s:
                answer += levels[child]
            else:
                levels[child] += 1
import code
code.interact(local=dict(globals(), **locals()))
print(answer)
