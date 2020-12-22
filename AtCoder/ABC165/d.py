from math import floor

def first(a, b, n, debug=False):
    from math import floor
    seen = set()
    prev = None
    seen = set()
    for x in range(b, n + 1, b):
        value = floor((a * x) / b) - a * floor(x / b)
        if prev is None:
            prev = value
            seen.add(value)
            continue
        if value != prev and value in seen:
            return max(seen)
        seen.add(value)
        prev = value
    else:
        return max(seen)

def second(a, b, n):
    m = float('-inf')
    for x in range(b, n + 1, b):
        m = max(m, floor((a * x) / b) - a * floor(x / b))
    return m
count = 0
while True:
    from random import randint
    a = randint(1, 10 ** 6)
    b = randint(1, 10 ** 12)
    n = randint(1, 10 ** 12)
    count += 1
    print(f'running with {a}, {b}, {n}...')
    if first(a, b, n) != second(a, b, n):
        print(a, b, n)
        import code
        code.interact(local=dict(globals(), **locals()))
    print(f'count = {count}')
