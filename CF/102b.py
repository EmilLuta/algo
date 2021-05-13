def go():
    n = input()
    c = 0
    while len(n) > 1:
        n = str(sum(int(i) for i in n))
        c += 1
    return c

print(go())
