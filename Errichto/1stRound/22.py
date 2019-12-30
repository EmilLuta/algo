# HW: https://www.spoj.com/problems/PT07Z/
# HW: https://codeforces.com/contest/1146/problem/C
# HW: Think about the tree diameter algorithm: Choose any vertex A. Find the furthest vertex B. Then, start from B and find the furthest vertex C. The path B-C is the diameter.

#####
# 1 #
#####

# n = int(input())
# tree = {}
# for _ in range(n):
#     x, y = map(int, input().split(' '))
#     tree.setdefault(x, [])
#     tree[x].append(y)
#     tree.setdefault(y, [])
#     tree[y].append(x)

# answer = 0
# def dfs(a):
#     global answer
#     current_max = prev_max = 0
#     if children[a]
#     for b in children[a]:
#         prev_max = current_max
#         current_max = dfs(b)
#     answer = max(answer, sum(x[:2])

# dfs(1)
# print(answer)

#####
# 2 #
#####

# t = int(input())
# for _ in range(t):
#     n = int(input())
#     answer = 0
#     power = 0
#     while 1 << power < n:
#         power += 1
#     for i in range(0, power):
#         a = set()
#         b = set()
#         mask = 1 << i
#         for j in range(1, n + 1):
#             if mask & j:
#                 a.add(j)
#             else:
#                 b.add(j)
#         print('{} {} {} {}'.format(len(a), len(b), ' '.join(str(i) for i in a), ' '.join(str(i) for i in b)))
#         answer = max(answer, int(input()))
#     print('{} {}'.format(-1, answer))

######
# 3a #
######

# n = int(input())
# tree = {}
# for _ in range(n - 1):
#     x, y = map(int, input().split(' '))
#     tree.setdefault(x, [])
#     tree[x].append(y)
#     tree.setdefault(y, [])
#     tree[y].append(x)

# visited = [False] * (n + 1)

# def longest_path_from(node):
#     if len(tree[node]) == 1 and visited[tree[node][0]]:
#         return 1, tree[node][0]
#     visited[node] = True
#     m = 0
#     n_m = None
#     for child in tree[node]:
#         if not visited[child]:
#             path, node = longest_path_from(child)
#             if m < path:
#                 m = path
#                 n_m = node
#     return m + 1, n_m

# _, a = longest_path_from(1)
# visited = [False] * (n + 1)
# m, _ = longest_path_from(a)
# print(m)

######
# 3b #
######

# n = int(input())
# tree = {}
# for _ in range(n - 1):
#     x, y = map(int, input().split(' '))
#     tree.setdefault(x, [])
#     tree[x].append(y)
#     tree.setdefault(y, [])
#     tree[y].append(x)



# def bfs(start):
#     depth = [-1] * (n + 1)
#     parent = [None] * (n + 1)
#     queue = [start]
#     depth[start] = 0
#     for node in queue:
#         for child in tree[node]:
#             if depth[child] == -1:
#                 depth[child] = depth[node] + 1
#                 parent[child] = node
#                 queue.append(child)
#     return depth[queue[-1]], queue[-1]

# _, a = bfs(1)
# m, _ = bfs(a)
# print(m)

