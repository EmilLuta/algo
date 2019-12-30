from collections import defaultdict

n = int(input())

graph = defaultdict(list)

for i in range(n - 1):
    a, b = map(int, input().split(' '))
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

size = [0] * n
maximum = 0
start = 0

def init(node, parent, distance):
    global start
    size[node] = 1
    start += distance + 1
    for children in graph[node]:
        if (children != parent):
            init(children, node, distance + 1)
            size[node] += size[children]

def dfs(node, parent, so_far):
    global maximum
    maximum = max(maximum, so_far)
    for children in graph[node]:
        if children != parent:
            dfs(children, node, so_far + n - 2 * size[children])

# RECURSION DEPTH EXCEEDED >.>
init(0, -1, 0)
dfs(0, -1, start)
print(maximum)

