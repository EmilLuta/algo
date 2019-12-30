from collections import defaultdict

def fix():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    keep = defaultdict(int)
    for i in range(n):
        keep[a[i] % 3] += 1
    c = keep[0]
    x = min(keep[1], keep[2])
    c += x
    keep[1] -= x
    keep[2] -= x
    if keep[1] > 0:
        c += keep[1] // 3
    if keep[2] > 0:
        c += keep[2] // 3
    return c

def go():
    t = int(input())
    for i in range(t):
        print(fix())
go()
