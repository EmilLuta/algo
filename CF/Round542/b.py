def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    b = [[] for _ in range(n)]
    for i in range(2 * n):
        b[a[i] - 1].append(i)
    s = 0
    d = 0
    total = 0
    for i in range(n):
        total += abs(b[i][0] - s)
        s = b[i][0]
        total += abs(b[i][1] - d)
        d = b[i][1]
    return total

print(go())
