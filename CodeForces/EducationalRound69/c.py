n, k = map(int, input().split(' '))
a = [int(i) for i in input().split(' ')]

k -= 1

total = 0

def split(a, start, end):
    # import code
    # code.interact(local=dict(globals(), **locals()))
    global k, total
    if end - start <= 1:
        return True
    m = float('inf')
    m_i = None
    for i in range(start, end):
        x = (a[i] - a[start]) + (a[end] - a[i + 1])
        # print(x)
        if m > x:
            m = x
            m_i = i
    print(f"Added {m}")
    total += m
    k -= 1
    x = a[m_i] - a[start]
    y = a[end] - a[m_i + 1]
    # import code
    # code.interact(local=dict(globals(), **locals()))
    if k == 0:
        return False
    if x > y:
        w = split(a, start, m_i)
        z = split(a, m_i + 1, end)
    else:
        z = split(a, m_i + 1, end)
        w = split(a, start, m_i)
    if w:
        total -= x
        print(f"Substracted {x}")
    if z:
        total -= y
        print(f'Substracted {y} with start: {start} and end: {end}')
    return True
m = float('inf')

split(a, 0, n - 1)
print(total)
