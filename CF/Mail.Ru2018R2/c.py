import math

def go():
    la, ra, ta = [int(c) for c in input().split(' ')]
    lb, rb, tb = [int(c) for c in input().split(' ')]

    if lb < la:
        la, lb = lb, la
        ra, rb = rb, ra
        ta, tb = tb, ta

    gcd = math.gcd(ta, tb)
    lena, lenb = ra - la + 1, rb - lb + 1
    d = lb - la
    diff = d - (d // gcd) * gcd
    cur = lena - diff

    ans = max(0, min(cur, lenb))

    diff -= gcd
    diff = -diff
    cur = lenb - diff
    ans = max(ans, min(lena, cur))
    return ans

print(go())
