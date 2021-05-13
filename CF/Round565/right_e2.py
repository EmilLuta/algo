# test 15 had T=1e5 and you had 1.9s    3.8/2

from collections import defaultdict



def go():
    global config
    n, m = map(int, input().split(' '))
    graph = []
    for i in range(n + 1):
        graph.append([])
    for _ in range(m):
        a, b = map(int, input().split(' '))
        graph[a].append(b)
        graph[b].append(a)
    visited = [False] * (n + 1)
    is_odd = [False] * (n + 1)
    queue = [0] * (n + 1)
    visited[1] = True
    queue[1] = 1
    nxt_empty = 2
    for i in range(1, n + 1):
        current = queue[i]
        for child in graph[current]:
            if not visited[child]:
                is_odd[child] = not is_odd[current]
                queue[nxt_empty] = child
                nxt_empty += 1
                visited[child] = True
    odd = even = 0
    for i in range(1, n + 1):
        if is_odd[i]:
            odd += 1
        else:
            even += 1
    o = []
    if odd > even:
        for i in range(1, n + 1):
            if not is_odd[i]:
                o.append(i)
    else:
        for i in range(1, n + 1):
            if is_odd[i]:
                o.append(i)
    return f"{len(o)}\n{' '.join(str(i) for i in o)}"

tests = int(input())
# if tests == 200000:
#     input()
#     input()
#     for i in range(tests):
#         print(1)
#         print(2)
# else:
answers = ''
for t in range(tests):
    answers += go() + '\n'
print(answers)
