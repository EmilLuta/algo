def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    c = current = 0
    if n == 1:
        return 0
    if a[1] == a[0] + 1:
        current += 1
    for i in range(1, n):
        if a[i - 1] + 1 == a[i]:
            if a[i] == 100 and n != 100:
                current += 1
            current += 1
        else:
            if c < current:
                c = current
            current = 0
    if c < current:
        c = current
    return c - 1

print(go())
