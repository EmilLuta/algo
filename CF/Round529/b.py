def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    if n == 2:
        return 0
    m1 = max(a)
    a.remove(m1)
    m2 = max(a)
    mi1 = min(a)
    a.remove(mi1)
    mi2 = min(a)
    if m2 - mi1 < m1 - mi2:
        return m2 - mi1
    return m1 - mi2

print(go())
