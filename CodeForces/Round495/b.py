def go():
    n, m = [int(i) for i in input().split(' ')]
    o = ''
    for i in range(m):
        input()
    for i in range(n):
        if i % 2 == 0:
            o += '0'
        else:
            o += '1'
    return o
print(go())
