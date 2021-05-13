def go():
    n, m = map(int, input().split(' '))
    half = (n + 1) // 2
    if m >= half:
        return n - m
    if m == 0:
        return 1
    return m

print(go())
