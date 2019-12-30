def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    x = a[0]
    i = 0
    while i < n and a[i] == x:
        current = a[i]
        i += 1
    so_far = i
    if n % so_far != 0:
        return 'No'
    for start in range(so_far, n, so_far):
        s = sum(a[start:start + so_far])
        if current == 0 and s != so_far:
            return 'No'
        if current == 1 and s != 0:
            return 'No'
        current = a[start]
    return 'Yes'

print(go())
