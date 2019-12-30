def check_others(os, pairs, x, y):
    for o in os:
        found = False
        for i, p in enumerate(pairs):
            if p is not None:
                if o[0] + p[0] == x and o[1] + p[1] == y:
                    pairs[i] = None
                    found = True
                    break
        if not found:
            return False
    return True


def go():
    n = int(input())
    x = 0
    y = 0
    for i in range(2 * n):
        a, b = [int(i) for i in input().split(' ')]
        x += a
        y += b
    return "{} {}".format(x // n, y // n)
print(go())
