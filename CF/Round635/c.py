from collections import defaultdict

n, k = [int(i) for i in input().split(' ')]
graph = defaultdict(list)
for i in range(n - 1):
    x, y = [int(i) for i in input().split(' ')]
    graph[x].append(y)
    graph[y].append(x)

levels = {1: 1}
children = defaultdict(int)
queue = [1]
index = 0
while index < len(queue):
    node = queue[index]
    index += 1
    for child in graph[node]:
        if child not in levels:
            queue.append(child)
            levels[child] = levels[node] + 1
            children[node] += 1
cities = list(sorted([(value, children[key], key) for key, value in levels.items()], key = lambda x: (-x[0], x[1])))
s = set()
for i in range(k):
    s.add(cities[i][2])
print(s)
levels = {}
if 1 in s:
    levels[1] = 0
else:
    levels[1] = 1
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
print(answer)
