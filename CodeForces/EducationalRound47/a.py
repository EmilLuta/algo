def go():
    n, m = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    i = j = 0
    while i < n and j < m:
        if a[i] <= b[j]:
            j += 1
        i += 1
    return j

print(go())
