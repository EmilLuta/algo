import math

def go():
    n, m, k, l = [int(i) for i in input().split(' ')]
    if m > n:
        return -1
    if n - k < l:
        return -1
    c = n // m
    a = math.ceil((k + l) / m)
    if a <= c:
        return a
    return -1

print(go())
