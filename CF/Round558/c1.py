from math import gcd
from collections import defaultdict

def go():
    n = int(input())
    points = []
    wires_set = set()
    unique_wires = defaultdict(int)
    for _ in range(n):
        x, y = map(int, input().split(' '))
        points.append((x, y))
    for i in range(n):
        for j in range(i + 1, n):
            a = points[i][1] - points[j][1]
            b = points[i][0] - points[j][0]
            c = points[i][1] * points[j][0] - points[j][1] * points[i][0]
            g = gcd(a, b)
            g = gcd(g, c)
            a //= g
            b //= g
            c //= g
            wires_set.add((a, b, c))
    for wire in wires_set:
        unique_wires[(wire[0], wire[1])] += 1
    x = len(unique_wires.keys())
    import code
    code.interact(local=locals())
    return (x * (x - 1)) // 2

print(go())
