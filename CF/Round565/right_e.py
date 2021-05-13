from collections import defaultdict

def go():
    global config
    n, m = map(int, input().split(' '))
    graph = defaultdict(list)
    for _ in range(m):
        a, b = map(int, input().split(' '))
        graph[a].append(b)
        graph[b].append(a)
    visited = [False] * (n + 1)
    levels = [0] * (n + 1)
    queue = [1]
    visited[1] = True
    odd = []
    even = [1]
    while queue:
        current = queue.pop()
        for child in graph[current]:
            if not visited[child]:
                levels[child] = levels[current] + 1
                if levels[child] % 2 == 0:
                    even.append(child)
                else:
                    odd.append(child)
                queue.append(child)
                visited[child] = True
    o = odd
    if len(odd) > len(even):
        o = even
    return f"{len(o)}\n{' '.join(str(i) for i in o)}"

for t in range(int(input())):
    print(go())
