# HW: There is a connected graph with N vertices and N edges. <= (skipt t
# 1) a tree with extra edge
# 2) a cycle with trees that grow out of this cycle
# Given Q queries with A and B, for each find the longest path between A and B. The path can't have repetitions.
# N, Q <= 100,000

# HW: You are given a tree with N <= 100,000 vertices. Count the number of paths that have odd length (the distance is odd).

# n, q = map(int, input().split(' '))
# graph = {}
# for i in range(n):
#     x, y = [int(i) for i in input().split(' ')]
#     graph.setdefault(x, [])
#     graph.setdefault(y, [])
#     graph[x].append(y)
#     graph[y].append(x)

# visited = [False] * (n + 1)
# parent = [None] * (n + 1)
# depths = [None] * (n + 1)
# cycle = []
# is_on_cycle = [False] * (n + 1)
# done = False

# def compute_cycle(x):
#     global done
#     visited[x] = True
#     for node in graph[x]:
#         if done:
#             return
#         if parent[x] == node:
#             continue
#         if visited[node]:
#             cycle.append(x)
#             is_on_cycle[x] = True
#             while x != node:
#                 x = parent[x]
#                 cycle.append(x)
#                 is_on_cycle[x] = True
#             done = True
#             return
#         parent[node] = x
#         compute_cycle(node)

# compute_cycle(1)

# position_on_cycle = [None] * (n + 1)

# distance_to_cycle = [0] * (n + 1)
# hits_node_in_cycle = [0] * (n + 1)

# for i in range(len(cycle)):
#     position_on_cycle[cycle[i]] = i

# def max_distance_on_cycle(x, y):
#     a = position_on_cycle[x]
#     b = position_on_cycle[y]
#     d = abs(a - b)
#     return max(d, len(cycle) - d)

# visited = [False] * (n + 1)
# def compute_distance_to_cycle(cycle_node, current_node, distance):
#     distance_to_cycle[current_node] = distance
#     hits_node_in_cycle[current_node] = cycle_node
#     visited[current_node] = True
#     for node in graph[current_node]:
#         if not visited[node] and not is_on_cycle[node]:
#             compute_distance_to_cycle(cycle_node, node, distance + 1)


# for x in cycle:
#     for node in graph[x]:
#         if not is_on_cycle[node]:
#             compute_distance_to_cycle(x, node, 1)

# def get_distance(a, b):
#     if is_on_cycle[a] and is_on_cycle[b]:
#         return max_distance_on_cycle(a, b)
#     if hits_node_in_cycle[a] == hits_node_in_cycle[b]:
#         return 'LCA'
#     a_hit = a
#     a_distance = 0
#     if not is_on_cycle[a]:
#         a_hit = hits_node_in_cycle[a]
#         a_distance = distance_to_cycle[a]
#     b_hit = b
#     b_distance = 0
#     if not is_on_cycle[b]:
#         b_hit = hits_node_in_cycle[b]
#         b_distance = distance_to_cycle[b]
#     return a_distance + b_distance + max_distance_on_cycle(a_hit, b_hit)

# for _ in range(q):
#     a, b = [int(i) for i in input().split(' ')]
#     print(get_distance(a, b))

''' HW
0) Think about an exact formula for the sum of values in a path if: a) edges have values/length, b) vertices
1) https://www.spoj.com/problems/LCA/
2) Add LCA to the cycle-problem code and test also on multiple trees growing from the same vertex on the cycle.
3) SPOJ problem with Fast LCA
'''

#####
# 0 #
#####

#####
# 1 #
#####

def dfs(tree, current_node, level, depth):
    depth[current_node] = level
    if current_node in tree:
        for child in tree[current_node]:
            dfs(tree, child, level + 1, depth)

def lca(a, b, parent, depth):
    while a != b:
        if depth[a] > depth[b]:
            a = parent[a]
        else:
            b = parent[b]
    return a


test_cases = int(input())
for case in range(test_cases):
    n = int(input())
    not_root = set()
    tree = {}
    parent = [None] * 1001
    depth = [None] * 1001
    for i in range(n):
        x = [int(i) for i in input().split(' ')]
        nodes = x[1:]
        not_root.update(nodes)
        for node in nodes:
            parent[node] = i + 1
            tree.setdefault(i + 1, [])
            tree[i + 1].append(node)
    root = None
    for i in range(n):
        if i + 1 not in not_root:
            root = i + 1
    dfs(tree, root, 1, depth)
    print('Case {}:'.format(case + 1))
    for _ in range(int(input())):
        a, b = [int(i) for i in input().split(' ')]
        print(lca(a, b, parent, depth))
    # for i in range(n):
        # for j in range(n):
            # print("LCA of {} - {} is {}".format(i + 1, j + 1, lca(i + 1, j + 1, parent, depth)))
#####
# 2 #
#####
# n, q = map(int, input().split(' '))
# graph = {}
# for i in range(n):
#     x, y = [int(i) for i in input().split(' ')]
#     graph.setdefault(x, [])
#     graph.setdefault(y, [])
#     graph[x].append(y)
#     graph[y].append(x)

# visited = [False] * (n + 1)
# parent = [None] * (n + 1)
# parents = {}
# depth = [None] * (n + 1)
# cycle = []

# def is_on_cycle(x):
#     return position_on_cycle[x] != None
# done = False

# def compute_cycle(x):
#     global done
#     visited[x] = True
#     for node in graph[x]:
#         if done:
#             return
#         if parent[x] == node:
#             continue
#         if visited[node]:
#             cycle.append(x)
#             while x != node:
#                 x = parent[x]
#                 cycle.append(x)
#             done = True
#             return
#         parent[node] = x
#         compute_cycle(node)

# compute_cycle(1)

# assert(done)


# position_on_cycle = [None] * (n + 1)

# distance_to_cycle = [0] * (n + 1)
# hits_node_in_cycle = [0] * (n + 1)

# for i in range(len(cycle)):
#     position_on_cycle[cycle[i]] = i

# visited = [False] * (n + 1)
# def compute_depth_and_parents(root, current_node, level):
#     depth[current_node] = level
#     if current_node in graph and not visited[current_node]:
#         visited[current_node] = True
#         for child in graph[current_node]:
#             if not is_on_cycle(child) and not visited[child]:
#                 parents[root][child][0] = current_node
#                 for k in range(1, 21):
#                     parents[root][child][k] = parents[root][parents[root][child][k-1]][k-1]
#                 compute_depth_and_parents(root, child, level + 1)

# for node in cycle:
#     parents[node] = []
#     for i in range(n + 1):
#         parents[node].append([])
#         for _ in range(21):
#             parents[node][i].append(0)


#     compute_depth_and_parents(node, node, 0)

# def get_lca1(root, a, b):
#     while a != b:
#         if depth[a] > depth[b]:
#             a = parents[root][a][0]
#         else:
#             b = parents[root][b][0]
#     return a

# def get_lca2(root, a, b):
#     if depth[a] < depth[b]:
#         a, b = b, a
#     mask = depth[a] - depth[b]
#     for k in range(0, 21):
#         if mask & (1 << k):
#             a = parents[root][a][k]
#     assert depth[a] == depth[b]
    
#     if(a == b):
#         return a
    
#     for k in range(20, -1, -1):
#         if parents[root][a][k] != parents[root][b][k]:
#             a = parents[root][a][k]
#             b = parents[root][b][k]
#     assert a != b
#     a = parents[root][a][0]
#     b = parents[root][b][0]
#     assert a == b
#     assert a != 0
#     return a

# def max_distance_on_cycle(x, y):
#     if x == y:
#         return 0
#     a = position_on_cycle[x]
#     b = position_on_cycle[y]
#     d = abs(a - b)
#     return max(d, len(cycle) - d)

# visited = [False] * (n + 1)
# def compute_distance_to_cycle(cycle_node, current_node, distance):
#     distance_to_cycle[current_node] = distance
#     hits_node_in_cycle[current_node] = cycle_node
#     visited[current_node] = True
#     for node in graph[current_node]:
#         if not visited[node] and not is_on_cycle(node):
#             compute_distance_to_cycle(cycle_node, node, distance + 1)


# for x in cycle:
#     hits_node_in_cycle[x] = x
#     for node in graph[x]:
#         if not is_on_cycle(node):
#             compute_distance_to_cycle(x, node, 1)

# def get_distance(a, b):
#     if is_on_cycle(a) and is_on_cycle(b):
#         return max_distance_on_cycle(a, b)
#     if hits_node_in_cycle[a] == hits_node_in_cycle[b]:
#         lca = get_lca1(hits_node_in_cycle[a], a, b)
#         return depth[a] + depth[b] - 2 * depth[lca]
#     return distance_to_cycle[a] + distance_to_cycle[b] + max_distance_on_cycle(hits_node_in_cycle[a], hits_node_in_cycle[b])

# for _ in range(q):
#     a, b = [int(i) for i in input().split(' ')]
#     print(get_distance(a, b))