""" Homework

1) Implement island with BFS

2) Think about a tree that answers queries:
"1 L R x" - for every i in interval [L, R], change a[i] to x
"2 i" - print a[i]

2a) implement your version with (x, last_time) - DONE
2b) implement a version with (x) only (avoid double memory)
Lazy propagation - when you are at vertex v, push its value to both its children

3) implement gcd problem from scratch (well, you can cheat a little bit and take my code)
TODO, next time (not your homework now)

4) https://codeforces.com/problemset/problem/574/B


Next time: binary search on a tree, Dijkstra

"""

# 1)

n = 4
m = [
    [0, 0, 0, 1],
    [1, 0, 1, 0],
    [1, 1, 1, 0],
    [1, 0, 1, 0],
]

visited = set()

count = 0

directions = ((-1, 0), (1, 0), (0, 0), (0, -1), (0, 1))

def is_inside(r, c):
    return 0 <= r and r < n and 0 <= c and c < n

def bfs(i, j):
    l = [(i, j)]
    for item in l:
        visited.add(item)
        for direction in directions:
            r = item[0] + direction[0]
            c = item[1] + direction[1]
            if is_inside(r, c) and (r, c) not in visited and m[r][c] == 1:
                l.append((r, c))

for i in range(n):
    for j in range(n):
        if m[i][j] == 1 and (i, j) not in visited:
            bfs(i, j)
            count += 1
print(count)

# 2b)

n, q = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

base = 1
while base < n:
    base *= 2

t = [None] * (base * 2)

for i in range(n):
    t[base + i] = a[i]

def change(i, s, e, q_s, q_e, v):
    if e < q_s or q_e < s:
        return
    if q_s <= s and q_e >= e:
        if t[i] is None:
            t[i] = v
            return
        if i < base:
            change(i * 2, s, e, q_s, q_e, t[i])
            change(i * 2 + 1, s, e, q_s, q_e, t[i])
        t[i] = v
        return
    mid = (s + e) // 2
    change(2 * i, s, mid, q_s, q_e, v)
    change(2 * i + 1, mid + 1, e, q_s, q_e, v)


def query(index):
    node = (base + index) // 2
    value = t[base + index]
    while node != 1:
        if t[node] is not None:
            value = t[node]
        node //= 2
    return value

for _ in range(q):
    x = [int(i) for i in input().split(' ')]
    if x[0] == 1:
        change(1, 0, base - 1, x[1], x[2], x[3])
    if x[0] == 2:
        print(query(x[1]))

# 3) Not this time

# 4)

n, m = [int(i) for i in input().split(' ')]
graph = {}

for _ in range(m):
    node = [int(i) for i in input().split(' ')]
    graph.setdefault(node[0], set())
    graph[node[0]].add(node[1])
    graph.setdefault(node[1], set())
    graph[node[1]].add(node[0])

options = set()

for i in graph:
    if len(graph[i]) >= 2:
        for j in graph[i]:
            if len(graph[j]) >= 2:
                for k in graph[j]:
                    if i in graph[j] and j in graph[k] and k in graph[i]:
                        options.add(tuple(sorted([i, j, k])))

minimum = 4000 * 3
if options:
    for option in options:
        minimum = min(minimum, len(graph[option[0]]) + len(graph[option[1]]) + len(graph[option[2]]) - 6)
    print(minimum)
else:
    print(-1)
