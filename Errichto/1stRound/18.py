""" Homework
1) For every edge in a tree, find the number of paths that contain this edge, O(N).
2) For every vertex in a tree, find the number of paths that contain this vertex, O(N). https://www.webwhiteboard.com/board/gbfjyd9k, https://en.wikipedia.org/wiki/Handshaking_lemma
    - make sure you understand the complexity correctly
3) Read chapters 4-6 in CPH.
"""

#####
# 1 #
#####

# n, m = map(int, input().split(' '))

# graph = {}
# pairs = []
# for _ in range(m):
#     x, y = map(int, input().split(' '))
#     pairs.append((x, y))
#     graph.setdefault(x, [])
#     graph.setdefault(y, [])
#     graph[x].append(y)
#     graph[y].append(x)

# subtree = [1] * (n + 1)

# visited = [False] * (n + 1)

# def dfs(node):
#     if not visited[node]:
#         visited[node] = True
#         for out in graph[node]:
#             if not visited[out]:
#                 dfs(out)
#                 subtree[node] += subtree[out]

# dfs(1)

# for x, y in pairs:
#     small_subtree = min(subtree[x], subtree[y])
#     print("Crossing edge {}-{} there are {} paths".format(x, y, small_subtree * (n - small_subtree)))


#####
# 2 #
#####

n = int(input())

graph = {}
for _ in range(n - 1):
    x, y = map(int, input().split(' '))
    graph.setdefault(x, [])
    graph.setdefault(y, [])
    graph[x].append(y)
    graph[y].append(x)

subtree = [1] * (n + 1)

visited = [False] * (n + 1)

def dfs(node):
    if not visited[node]:
        visited[node] = True
        for out in graph[node]:
            if not visited[out]:
                dfs(out)
                subtree[node] += subtree[out]

dfs(1)

for i in range(1, n + 1):
    paths = 0
    nodes_left = subtree[i]
    for out in graph[i]:
        if subtree[i] < subtree[out]:
            paths += subtree[i] * (n - subtree[i])
        else:
            nodes_left -= subtree[out]
            paths += subtree[out] * (nodes_left)
    print('The number of paths that goes through node {} is {}'.format(i, paths))
