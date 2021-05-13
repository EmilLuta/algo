def go():
    n, _ = map(int, input().split(' '))
    s = set()
    a = [int(i) for i in input().split(' ')]
    for i in a:
        s.add((i, i))
        if i > 1:
            if (i - 1, i - 1) in s:
                s.add((i, i - 1))
        if i < n:
            if (i + 1, i + 1) in s:
                s.add((i, i + 1))
    return n * 3 - 2 - len(s)

print(go())
