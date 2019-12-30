'''
1) Binary search on a max tree: for every number, find the next number that is greater
2) Implement max problem from scratch - sum of max of all intervals
3) Implement gcd problem from scratch
4) Implement Dijkstra, https://www.spoj.com/problems/EZDIJKST/

5)? Next time: Floyd-Warshall
'''

#####
# 1 #
#####
n, queries = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

base = 1

while base < n:
    base *= 2

minus_inf = float('-inf')
t = [minus_inf] * (base * 2)

for i in range(n):
    t[base + i] = a[i]

for i in range(base - 1, 0, -1):
    t[i] = max(t[i * 2], t[i * 2 + 1])

def search(i):
    node = base + i
    if i == n - 1:
        return 'no number bigger than {}'.format(t[node])
    while node > 1:
        if node % 2 == 0:
            if t[node] < t[node + 1]:
                node += 1
                break
        node //= 2
    if node == 1:
        return 'no number bigger than {}'.format(a[i])
    while node < base:
        if t[base + i] < t[node * 2]:
            node = node * 2
        else:
            node = node * 2 + 1
    return 'next bigger number than {} is {}'.format(a[i], t[node])

for q in range(queries):
    i = int(input())
    print(search(i))

# ERRICHTO
n, queries = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

base = 1

while base < n:
    base *= 2

minus_inf = float('-inf')
t = [minus_inf] * (base * 2)

for i in range(n):
    t[base + i] = a[i]

for i in range(base - 1, 0, -1):
    t[i] = max(t[i * 2], t[i * 2 + 1])

def search(i):
    node = base + i
    x = t[base + i]
    if i == n - 1:
        return 'no number bigger than {}'.format(t[node])
    while node > 1:
        if node % 2 == 0:
            if x < t[node + 1]:
                node += 1
                break
        node //= 2
    if node == 1:
        return 'no number bigger than {}'.format(a[i])
    while node < base:
        if x < t[node * 2]:
            node = node * 2
        else:
            node = node * 2 + 1
    return 'next bigger number than {} is {}'.format(a[i], t[node])

for q in range(queries):
    i = int(input())
    print(search(i))

#####
# 2 #
#####
n = int(input())
a = [int(i) for i in input().split(' ')]

base = 1

while base < n:
    base *= 2

minus_inf = float('-inf')
t = [minus_inf] * (base * 2)

for i in range(n):
    t[base + i] = a[i]

for i in range(base - 1, 0, -1):
    t[i] = max(t[i * 2], t[i * 2 + 1])

def search(node):
    keep = node
    while node > 1:
        if node % 2 == 0:
            if t[node] < t[node + 1]:
                node += 1
                break
        node //= 2
    if node == 1:
        return
    while node < base:
        if t[keep] < t[node * 2]:
            node = node * 2
        else:
            node = node * 2 + 1
    return node

total = 0
for i in range(n - 1):
    x = prev = base + i
    while x is not None:
        prev = x
        x = search(x)
        if x is None:
            total += (base * 2 - prev) * t[prev]
        else:
            total += (x - prev) * t[prev]
print(total + a[-1])

#####
# 3 #
#####
from math import gcd

n = int(input())
a = [int(i) for i in input().split(' ')]

base = 1

while base < n:
    base *= 2

minus_inf = float('-inf')
t = [minus_inf] * (base * 2)

for i in range(n):
    t[base + i] = a[i]

for i in range(base - 1, 0, -1):
    t[i] = gcd(t[i * 2], t[i * 2 + 1])

def search(node, current_gcd):
    while node > 1:
        if node % 2 == 0:
            if t[node + 1] % current_gcd != 0:
                node += 1
                break
        node //= 2
    if node == 1:
        return None, None
    while node < base:
        if t[node * 2] % current_gcd != 0:
            node = node * 2
        else:
            node = node * 2 + 1
    return node, gcd(current_gcd, t[node])

total = 0
for i in range(n - 1):
    x = prev = base + i
    current_gcd = prev_gcd = None
    while x is not None:
        prev = x
        prev_gcd = current_gcd
        x, current_gcd = search(x, current_gcd or t[prev])
        if x is None:
            total += (base * 2 - prev) * (prev_gcd or t[prev])
        else:
            total += (x - prev) * (prev_gcd or t[prev])
print(total + a[-1])

#####
# 4 #
#####
import heapq

cases = int(input())
inf = float('inf')
for _ in range(cases):
    n, m = [int(i) for i in input().split(' ')]
    h = []
    dist = [inf] * (n + 1)
    visited = [False] * (n + 1)
    graph = {}

    for _ in range(m):
        x = [int(i) for i in input().split(' ')]
        graph.setdefault(x[0], [])
        graph[x[0]].append((x[1], x[2]))
    start, end = [int(i) for i in input().split(' ')]
    dist[start] = 0
    heapq.heappush(h, (dist[start], 1))
    while h:
        item = heapq.heappop(h)
        a = item[1]
        if visited[a]:
            continue
        visited[a] = True
        if a in graph:
            for p in graph[a]:
                b = p[0]
                l = p[1]
                if dist[b] > dist[a] + l:
                    dist[b] = dist[a] + l
                    heapq.heappush(h, (dist[b], b))
    if dist[end] != inf:
        print(dist[end])
    else:
        print('NO')

#####
# 5 #
#####

n, m = [int(i) for i in input().split(' ')]
inf = float('inf')
pairs = []
dp = []
for i in range(n + 1):
    dp.append([])
    for j in range(n + 1):
        if i == j:
            dp[i].append(0)
        else:
            dp[i].append(inf)

for _ in range(m):
    x = [int(i) for i in input().split(' ')]
    pairs.append((x[0], x[1], x[2]))

start, end = [int(i) for i in input().split(' ')]

for pair in pairs:
    dp[pair[0]][pair[1]] = pair[2]

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if dp[i][j] > dp[i][k] + dp[k][j]:
                dp[i][j] = dp[i][k] + dp[k][j]

if dp[start][end] != inf:
    print(dp[start][end])
else:
    print("NO")
