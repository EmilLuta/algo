from collections import defaultdict
from math import sqrt


def solve(d, n):
    s = 0
    used = [False] * (n + 1)
    for key in d:
        value = d[key]
        while used[value] and value > 0:
            value -= 1
        s += value
        used[value] = True
    return s

def go():
    n = int(input())
    d_all = defaultdict(int)
    d_ones = defaultdict(int)
    for i in range(n):
        item, ok = map(int, input().split(' '))
        if ok == 1:
            d_ones[item] += 1
        d_all[item] += 1
    return f'{solve(d_all, n)} {solve(d_ones, n)}'

o = ''
Q = int(input())
for _ in range(Q):
    o += str(go()) + '\n'
print(o)
