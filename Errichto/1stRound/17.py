""" Homework
1) Fix previous homework problems.
    a) Binary search on a max tree: for every number, find the next number that is greater
    b) Implement max problem from scratch - sum of max of all intervals
    c) Implement gcd problem from scratch
    d) Implement Dijkstra, https://www.spoj.com/problems/EZDIJKST/
2) Read CPH book up to page 34.
----------
3) Solve https://www.spoj.com/problems/DIVSUM/ faster than O(N).
4) For every edge in a tree, find the number of paths that contain this edge, O(N).
4*) For every vertex in a tree, find the number of paths that contain this vertex, O(N).
"""

######
# 1a #
######

n = 10
a = [1, 4, 5, 3, 9, 0, 6, 7, 8, 2, 'not available']
base = 1
while base < n:
    base *= 2

minus_inf = float('-inf')
tree = [minus_inf] * (base * 2) + ['no bigger node']

for i in range(n):
    tree[base + i] = a[i]

for i in range(base - 1, 0, -1):
    tree[i] = max(tree[i * 2], tree[i * 2 + 1])

def next_bigger(i):
    to_compare = a[i]
    node = base + i
    while node != 1:
        if node % 2 == 0 and to_compare < tree[node + 1]:
            node += 1
            break
        node //= 2

    if node == 1:
        return n

    while node < base:
        if to_compare < tree[node * 2]:
            node = node * 2
        else:
            node = node * 2 + 1
    return node - base


for i in range(n):
    position = next_bigger(i)
    print("Next bigger number than {} at position {} is {} at position {}".format(a[i], i, a[position], position))

######
# 1b #
######

n = 10
a = [1, 4, 5, 3, 9, 0, 6, 7, 8, 2]

total = 0
for i in range(n):
    for j in range(i, n):
        total += max(a[i:j + 1])
print(total)

base = 1
while base < n:
    base *= 2

tree = [0] * (base * 2)
for i in range(n):
    tree[base + i] = a[i]

for i in range(base - 1, 0, -1):
    tree[i] = max(tree[i * 2], tree[i * 2 + 1])

def next_bigger(i):
    node = base + i
    while node > 1:
        if node % 2 == 0:
            if tree[node + 1] > a[i]:
                node += 1
                break
        node //= 2

    if node == 1:
        return n
    while node < base:
        node *= 2
        if tree[node] < a[i]:
            node += 1
    return node - base

def prev_bigger(i):
    node = base + i
    while node > 1:
        if node % 2 == 1:
            if tree[node - 1] > a[i]:
                node -= 1
                break
        node //= 2
    if node == 1:
        return -1
    while node < base:
        node *= 2
        if tree[node + 1] > a[i]:
            node += 1
    return node - base
total = 0
for i in range(n):
    total += (next_bigger(i) - i) * (i - prev_bigger(i)) * a[i]
print(total)


###### WRONG ^^^

a = [2, 5, 2, 1, 1, 1, 2, 1, 5, 5, 5, 1, 2, 5, 4, 5]
n = len(a)

total = 0
for i in range(n):
    for j in range(i, n):
        total += max(a[i:j + 1])
print(total)
 
base = 1
while base < n:
    base *= 2
 
tree = [0] * (base * 2)
for i in range(n):
    tree[base + i] = a[i]
 
for i in range(base - 1, 0, -1):
    tree[i] = max(tree[i * 2], tree[i * 2 + 1])
 
def next_bigger(i):
    node = base + i
    while node > 1:
        if node % 2 == 0:
            if tree[node + 1] > a[i]:
                node += 1
                break
        node //= 2
 
    if node == 1:
        return n
    while node < base:
        node *= 2
        if tree[node] <= a[i]:
            node += 1
    return node - base
 
def prev_bigger(i):
    x = a[i] - 1
    node = base + i
    while node > 1:
        if node % 2 == 1:
            if tree[node - 1] > x:
                node -= 1
                break
        node //= 2
    if node == 1:
        return -1
    while node < base:
        node = 2 * node + 1
        if tree[node] <= x:
            node -= 1
    return node - base
total = 0

for i in range(n):
    print(prev_bigger(i), next_bigger(i))
    total += (next_bigger(i) - i) * (i - prev_bigger(i)) * a[i] # <---
print(total)

######
# 1c #
######

from math import gcd

n = 8
a = [60, 180, 120, 140, 20, 40, 15, 3]

total = 0
for i in range(n):
    curr_gcd = a[i]
    total += curr_gcd
    for j in range(i + 1, n):
        curr_gcd = gcd(curr_gcd, a[j])
        total += curr_gcd
print(total)

base = 1

while base < n:
    base *= 2

t = [0] * (base * 2)

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
        return base+n, None
    while node < base:
        if t[node * 2] % current_gcd != 0:
            node = node * 2
        else:
            node = node * 2 + 1
    return node, gcd(current_gcd, t[node])

total = 0
for i in range(n - 1):
    x = base + i
    current_gcd = t[base + i]
    while x < base + n:
        prev = x
        prev_gcd = current_gcd
        x, current_gcd = search(x, current_gcd)
        total += (x - prev) * prev_gcd
print(total + a[-1])


######
# 1d #
######

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
    heapq.heappush(h, (dist[start], start))
    while h:
        item = heapq.heappop(h)
        a = item[1]
        if visited[a]:
            continue
        visited[a] = True
        if a in graph:
            for p in graph[a]:
                b = p[0]
                distance = p[1]
                if dist[b] > dist[a] + distance:
                    dist[b] = dist[a] + distance
                    heapq.heappush(h, (dist[b], b))
    if dist[end] != inf:
        print(dist[end])
    else:
        print('NO')

#####
# 2 #   DONE
#####

#####
# 3 #
#####

from math import ceil, sqrt

n = int(input())

for i in range(n):
    number = int(input())
    total = 1
    for j in range(2, ceil(sqrt(number))):
        d = number // j
        m = number % j
        if m == 0:
            total += j + d
    print(total)

#####
# 4 #
#####
