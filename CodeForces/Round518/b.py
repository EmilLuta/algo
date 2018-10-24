from math import sqrt

def go():
    n = int(input())
    if n == 1:
        return 1
    i = 1
    c = 0
    while i <= sqrt(n):
        if n % i == 0:
            if n // i == i:
                c += 1
            else:
                c += 2
        i += 1
    return c

print(go())
