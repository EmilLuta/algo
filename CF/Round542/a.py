from math import ceil

def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    pos = neg = zero = 0
    for i in range(n):
        if a[i] > 0:
            pos += 1
        elif a[i] < 0:
            neg += 1
        else:
            zero += 1
    if pos >= ceil(n / 2):
        return 1
    if neg >= ceil(n / 2):
        return -1
    return 0

print(go())
