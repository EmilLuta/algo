def my(n, k):
    out = ''
    return str(k + (k - 1) // (n - 1))
    x = k // n
    if k % (n - 1) == 0:
        x += 1
    return str(k + x)

def bf(n, k):
    x = 1
    out = []
    while len(out) < k:
        if x % n != 0:
            out.append(x)
        x += 1
    return str(out[-1])

n, x = [int(i) for i in input().split(' ')]
for k in range(1, x + 1):
    print(n, k)
    m = my(n, k)
    b = bf(n, k)
    if m != b:
        import code
        code.interact(local=dict(globals(), **locals()))
    # assert my(n, k) == bf(n, k)
