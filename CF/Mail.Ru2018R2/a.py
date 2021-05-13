def go():
    n, s = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    if a[0] == 0:
        return 'NO'
    if a[s - 1] == 1:
        return 'YES'
    if b[s - 1] == 0:
        return 'NO'
    for i in range(s, n):
        if a[i] == 1 and b[i] == 1:
            return 'YES'
    return 'NO'

print(go())
