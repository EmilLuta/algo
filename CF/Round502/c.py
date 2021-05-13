def go():
    n = int(input())
    o = [str(i) for i in range(n, 0, -1)]
    print(o)
    return ' '.join(o)

print(go())
