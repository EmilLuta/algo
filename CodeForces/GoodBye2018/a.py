def go():
    y, b, r = [int(i) for i in input().split(' ')]
    x = min(y, b, r)
    if x == r:
        return r + r - 1 + r - 2
    elif x == b:
        return b + 1 + b + b - 1
    else:
        if r >= y + 2:
            return y + y + 1 + y + 2
        else:
            return y - 1 + y + y + 1

print(go())
