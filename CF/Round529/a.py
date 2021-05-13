def go():
    n = int(input())
    a = [i for i in input()]
    i = 0
    j = 1
    o = ''
    while i < n:
        o += a[i]
        i += j
        j += 1
    return o

print(go())
