def go():
    n = int(input())
    m = 0
    for i in range(n):
        a, b = [int(i) for i in input().split(' ')]
        m = max(a + b, m)
    return m

print(go())
