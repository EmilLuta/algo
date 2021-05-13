def go():
    n, m = map(int, input().split())
    v = [int(input()) for i in range(n)]
    v.append(10**9)
    h = []
    for i in range(m):
        f, t, d = map(int, input().split())
        if f == 1:
            h.append(t)
    v.sort()
    h.sort()
    j = 0
    minimum = float('inf')
    for i in range(len(v)):
        while j < len(h) and v[i] > h[j]:
            j += 1
        if minimum > i + len(h) - j:
            minimum = i + len(h) - j
        if j == len(h):
            break
    return minimum

print(go())
