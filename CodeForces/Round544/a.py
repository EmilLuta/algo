def go():
    h1, m1 = map(int, input().split(':'))
    h2, m2 = map(int, input().split(':'))
    t = ((m2 - m1) + (h2 - h1) * 60) // 2
    m = m1 + t % 60
    h = str(h1 + t // 60 + m // 60)
    m = str(m % 60)
    if len(m) == 1:
        m = '0' + m
    if len(h) == 1:
        h = '0' + h
    return "{}:{}".format(h, m)

print(go())
