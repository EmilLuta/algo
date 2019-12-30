from collections import defaultdict

output = set()
graph = defaultdict(set)
can_reach = set()
n = 0

def dfs(node):
    # import code
    # code.interact(local=dict(globals(), **locals()))
    global output, graph, can_reach, n
    if node in can_reach or len(can_reach) == n:
        return
    output.add(node)
    can_reach.add(node)
    for child in graph[node]:
        if child in can_reach:
            return
        can_reach.add(child)
        for gchild in graph[child]:
            if gchild not in can_reach:
                # import code
                # code.interact(local=dict(globals(), **locals()))
                dfs(gchild)


def fix():
    global output, graph, n
    n, m = map(int, input().split(' '))
    for _ in range(m):
        x, y = map(int, input().split(' '))
        graph[x].add(y)
        graph[y].add(x)
    dfs(1)
    return '{}\n{}'.format(len(output), ' '.join(str(i) for i in output))

def go():
    global output, graph, can_reach
    t = int(input())
    for _ in range(t):
        print(fix())
        import code
        code.interact(local=dict(globals(), **locals()))
        output = set()
        graph = defaultdict(set)
        can_reach = set()

go()
