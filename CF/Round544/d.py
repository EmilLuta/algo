from math import gcd

def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    d = {}
    m = 0
    z = 0
    for i in range(n):
        if a[i] == 0 and b[i] == 0:
            z += 1
        elif a[i] == 0:
            continue
        elif b[i] == 0:
            d.setdefault(0, 0)
            d[0] += 1
            m = max(m, d[0])
        else:
            g = gcd(a[i], b[i])
            b_m = b[i] // g
            a_m = a[i] // g
            sign = '-' if b_m // a_m < 0 else '+'
            b_m = abs(b_m)
            a_m = abs(a_m)
            d.setdefault((sign, b_m, a_m), 0)
            d[(sign, b_m, a_m)] += 1
            m = max(m, d[(sign, b_m, a_m)])
    return m + z

print(go())
