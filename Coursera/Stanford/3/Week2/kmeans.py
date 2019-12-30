from collections import defaultdict

def load_data():
    with open('input_small.txt', 'r') as f:
        n = int(next(f))
        graph = []
        for i in range(n):
            graph.append([])
            for j in range(n):
                graph[i].append(float('inf'))
        for line in f:
            a, b, w = [int(i) for i in line.split(' ')]
            a -= 1
            b -= 1
            graph[a][b] = graph[b][a] = w
    return n, graph

def kmeans():
    n, graph = load_data()
    means = []
    for i in range(n):
        means.append(i)
    k = n
    while k != 4:
        m = float('inf')
        x = y = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                if graph[i][j] < m:
                    m = graph[i][j]
                    x = i
                    y = j
        graph[x][y] = float('inf')
        graph[y][x] = float('inf')
        leader_x = means[x]
        same_component = []
        x_c = y_c = 0
        for i in range(n):
            if means[x] == means[i]:
                x_c += 1
            if means[y] == means[i]:
                y_c += 1
        if x_c > y_c:
            for i in range(n):
                if means[y] == means[i]:
                    means[i] = means[x]
        else:
            for i in range(n):
                if means[x] == means[i]:
                    means[i] = means[y]
        k -= 1
    import code
    code.interact(local=dict(globals(), **locals()))
kmeans()
