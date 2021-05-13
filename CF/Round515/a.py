import math
def go():
    n = int(input())
    for i in range(n):
        L, v, l, r = [int(i) for i in input().split(' ')]
        L = L // v * v
        left = (l - 1) // v
        if r % v == 0:
            right = (L - r) // v
        elif r == L:
            right = 0
        else:
            right = (L - r) // v + 1
        print(right + left)
go()
