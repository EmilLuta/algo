t = int(input())

for _ in range(t):
    n, x = [int(i) for i in input().split(' ')]
    a = []
    m = 0
    m_d = 0
    d_m = None
    for j in range(n):
        d, h = [int(i) for i in input().split(' ')]
        if m_d < d - h:
            m_d = d - h
            d_m = d
        m_d = max(m_d, d - h)
        m = max(m, d)
    a.sort(reverse=True)
    # import code
    # code.interact(local=dict(globals(), **locals()))
    c = 0
    while x > 0:
        if m > n:
            c += 1
            print(c)
            break
        if x - d <= 0:
            c += 1
            print(c)
            break
        elif x - m <= 0:
            c += 1
            print(c)
            break
        else:
            x -= m_d
            c += 1
    else:
        print(c)

