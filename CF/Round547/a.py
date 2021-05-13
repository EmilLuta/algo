def go():
    n, m = map(int, input().split(' '))
    if m % n != 0: 
        return -1
    d = m / n
    c = 0
    while d % 2 == 0:
        d /= 2
        c += 1
    while d % 3 == 0:
        d /= 3
        c += 1
    if d == 1:
        return c
    return -1

print(go())