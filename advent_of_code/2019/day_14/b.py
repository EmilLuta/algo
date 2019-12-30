from collections import defaultdict

ore_so_far = 0

def add_to_graph(graph, line):
    n = len(line)
    quantity = ""
    t = ""
    values = []
    for i in range(n):
        if line[i] >= '0' and line[i] <= '9':
            quantity += line[i]
        elif line[i] >= 'A' and line[i] <= 'Z':
            t += line[i]
        elif line[i] == ',' or line[i] == '=':
            values.append((t, int(quantity)))
            t = ""
            quantity = ""
            if line[i] == '=':
                i += 1
    graph[t] = (int(quantity), values)

def dfs(graph, cache, node, how_many):
    global ore_so_far
    initial = how_many
    x = how_many // graph[node][0]
    if how_many % graph[node][0] != 0:
        x += 1
    how_many = x
    for children in graph[node][1]:
        w = how_many * children[1]
        if children[0] == "ORE":
            ore_so_far += w
            continue
        if children[0] in cache:
            if cache[children[0]] > w:
                cache[children[0]] -= w
                continue
            if cache[children[0]] == w:
                cache.pop(children[0])
                continue
            w -= cache[children[0]]
            cache.pop(children[0])
        dfs(graph, cache, children[0], w)
    if how_many * graph[node][0] > initial:
        cache[node] = how_many * graph[node][0] - initial

def main():
    global ore_so_far
    graph = {'ORE': [1]}
    cache = defaultdict(int)
    with open('input.txt', 'r') as f:
        for line in f.read().strip().split('\n'):
            add_to_graph(graph, line)
        node = "FUEL"
        count = 0
        while ore_so_far <= 1000000000000:
            dfs(graph, cache, node, graph[node][0])
            count += 1
            print(ore_so_far)
        print('OUT')
        print(ore_so_far)
        print(count - 1)
        # print(cache)

main()
