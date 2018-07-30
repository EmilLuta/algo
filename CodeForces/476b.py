def w(n, o, x):
    if len(n) == x:
        o.append(n)
        return
    w(n + '-', o, x)
    w(n + '+', o, x)

def go():
    a = [i for i in input()]
    b = [i for i in input()]
    s_a = 0
    s_b = 0
    u = 0
    for i in a:
        if i == '-':
            s_a -= 1
        else:
            s_a += 1
    for i in b:
        if i == '-':
            s_b -= 1
        elif i == '+':
            s_b += 1
        else:
            u += 1
    if u == 0:
        if s_a == s_b:
            return float(1)
        return float(0)
    o = []
    w('', o, u)
    c = 0
    for i in range(len(o)):
        s_x = s_b
        for j in o[i]:
            if j == '-':
                s_x -= 1
            else:
                s_x += 1
        if s_x == s_a:
            c += 1
    return c / len(o)

print(go())
