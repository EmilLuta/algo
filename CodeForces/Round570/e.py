def go():
    n, k = map(int, input().split(' '))
    a = input()
    s = set()
    size = n
    c = 0
    while len(s) != k and size > 0:
        for i in range(n - size + 1):
            x = a[i:i + size]
            # import code
            # code.interact(local=dict(globals(), **locals()))
            if x not in s:
                s.add(x)
                if len(s) == k:
                    break
                c += n - size
        size -= 1
    print(s)
    if len(s) == k:
        return c
    if len(s) == k - 1:
        return c + n
    return -1

print(go())
