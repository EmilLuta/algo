from collections import defaultdict
from math import sqrt


def go():
    n = int(input())
    s = 0
    d = defaultdict(int)
    for item in input().split(' '):
        d[int(item)] += 1
    used = [False] * (n + 1)
    for key in d:
        value = d[key]
        while used[value] and value > 0:
            value -= 1
        s += value
        used[value] = True
    return s

o = ''
Q = int(input())
for _ in range(Q):
    o += str(go()) + '\n'
print(o)
