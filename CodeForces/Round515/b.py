def go():
    n, r = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    c = 0
    last = -1
    while last < n - 1:
        pos = -1
        for i in range(n - 1, max(-1, last - r + 1), -1):
            if a[i] == 1 and i - r <= last:
                pos = i
                break
        if pos == -1:
            return -1
        c += 1
        last = pos + r - 1
    return c

print(go())
