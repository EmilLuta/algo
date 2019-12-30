# HW:
# https://codeforces.com/contest/1146/problem/C
# i) Get a terminal node on the diamter Q(1, rest) = longesth path to node A          log(N)    Binary search B from 2 to N, such that dist(1, B) is maximized.
#             is valid B in interval [L, R] --- we can with query dist(1, set[L,R])
# ii) Find the other terminal node of the diamter Q(B, rest) O(1)
# HW: https://www.spoj.com/problems/LCA/ Try with writing from scratch/ BFS instead of DFS/ huge number for array size/ dictionaries instead of arrays
# HW: for GCJ A, solve one-dimensional case in O(N+Q)
# HW: solve one-dimensional case in O(N+Q)

#####
# 1 #
#####
# t = int(input())
# for _ in range(t):
#     n = int(input())
#     print('1 {} 1 {}'.format(n - 1, ' '.join(str(i) for i in range(2, n + 1))))
#     aim = int(input())
#     start = 2
#     end = n
#     while start != end:
#         mid = (start + end) // 2
#         a = [i for i in range(start, mid + 1)]
#         print('1 {} 1 {}'.format(len(a), ' '.join(str(i) for i in a)))
#         answer = int(input())
#         if answer == aim:
#             end = mid
#         else:
#             start = mid + 1

#     a = [i for i in range(1, n + 1) if i != start]
#     print('1 {} {} {}'.format(len(a), start, ' '.join(str(i) for i in a)))
#     print('-1 {}'.format(input()))

#####
# 2 #
#####
from collections import defaultdict

def lca1(depth, parent, a, b):
    while a != b:
        if depth[a] > depth[b]:
            a = parent[a]
        else:
            b = parent[b]
    return a

def lca(depth, parent, a, b):
    if depth[a] < depth[b]:
        a, b = b, a
    mask = depth[a] - depth[b]
    for k in range(0, 21):
        if mask & (1 << k):
            a = parent[a][k]
    assert depth[a] == depth[b]
    if(a == b):
        return a
    for k in range(20, -1, -1):
        if parent[a][k] != parent[b][k]:
            a = parent[a][k]
            b = parent[b][k]
    assert a != b
    a = parent[a][0]
    b = parent[b][0]
    assert a == b
    assert a != 0
    return a


n_test = int(input())
for t in range(n_test):
    n = int(input())
    parent = []
    depth = []
    for i in range(n + 1):
        parent.append([])
        for _ in range(21):
            parent[i].append(0)
        depth.append(0)
    tree = defaultdict(list)
    for i in range(1, n + 1):
        for raw_node in input().split(' ')[1:]:
            node = int(raw_node)
            tree[i].append(node)
            parent[node][0] = i
            for k in range(1, 21):
                parent[node][k] = parent[parent[node][k-1]][k-1]
    root = 0
    for i in range(1, n + 1):
        if parent[i][0] == 0:
            root = i
            break
    queue = [root]
    for node in queue:
        for child in tree[node]:
            depth[child] = depth[parent[child][0]] + 1
            queue.append(child)
    queries = int(input())
    print("Case {}:".format(t + 1))
    for q in range(queries):
        print(lca(depth, parent, *[int(i) for i in input().split(' ')]))
