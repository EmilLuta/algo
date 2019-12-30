from math import gcd

from collections import defaultdict

def go():
    n = int(input())
    pairs = []
    for _ in range(n):
        pairs.append([int(i) for i in input().split(' ')])
    total = 0
    result = 0
    wires = defaultdict(set)
    for i in range(n):
        for j in range(i + 1, n):
            x1, y1 = pairs[i]
            x2, y2 = pairs[j]
            a = y1 - y2
            b = x1 - x2
            g = gcd(a, b)
            if (a < 0 or (a == 0 and b < 0)):
                a = -a
                b = -b
            a //= g
            b //= g
            wires[(a, b)]
            c = a * x1 - b * y1
            pair = (a, b)
            if c not in wires[pair]:
                wires[pair].add(c)
                total += 1
                result += total - len(wires[pair])
    return result

print(go())
