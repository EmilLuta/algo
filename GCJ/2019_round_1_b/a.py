import operator

from collections import defaultdict

t = int(input())
for test_case in range(t):
    p, q = map(int, input().split(' '))
    graph = defaultdict(int)
    for i in range(p):
        point = input().split(' ')
        x = int(point[0])
        y = int(point[1])
        if point[2] == 'N':
            for xx in range(0, q + 1):
                for yy in range(y + 1, q + 1):
                    graph[(xx, yy)] += 1
        if point[2] == 'S':
            for xx in range(0, q + 1):
                for yy in range(0, y):
                    graph[(xx, yy)] += 1
        if point[2] == 'E':
            for xx in range(x + 1, q + 1):
                for yy in range(0, q + 1):
                    graph[(xx, yy)] += 1
        if point[2] == 'W':
            for xx in range(0, x):
                for yy in range(0, q + 1):
                    graph[(xx, yy)] += 1
        m = 0
        values = []
        for key in graph:
            if m < graph[key]:
                values = [key]
                m = graph[key]
            if m == graph[key]:
                values.append(key)
    print('Case #{}: {} {}'.format(test_case + 1, *min(values, key=operator.itemgetter(0, 1))))


        