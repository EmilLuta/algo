def just_one(x):
    if x == 1:
        return 0
    x -= 2
    return 1 + x // 3

def get_value(n, m):
    n -= 2
    c = (1 + n // 3) * ((m + 1) // 2)
    if n % 3 == 2:
        c += just_one(m)
    return c

def go():
    n, m = [int(i) for i in input().split(' ')]
    if n == 1:
        return just_one(m)
    if m == 1:
        return just_one(n)
    # import code
    # code.interact(local=dict(globals(), **locals()))
    return max(get_value(n, m), get_value(m, n))

print(go())
