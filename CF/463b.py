def go():
    n = int(input())
    a = [0] + [int(i) for i in input().split(' ')]
    c = 0
    added = 0
    for i in range(n):
        if a[i] + c >= a[i + 1]:
            c += a[i] - a[i + 1]
        else:
            added += a[i + 1] - (a[i] + c)
            c = 0
    return added

print(go())
