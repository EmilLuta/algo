def go():
    a, d, m = [int(i) for i in input().split(' ')]
    g, p, b = [int(i) for i in input().split(' ')]
    if g < a:
        return "NO"
    g -= a
    w = g + p
    if w < d:
        return "NO"
    w -= d
    w += b
    if w < m:
        return "NO"
    return "YES"

print(go())
