def go():
    n = int(input())
    a = [i for i in input()]
    x = 0
    for i in a:
        if i == '-':
            x = max(0, x - 1)
        else:
            x += 1
    return x

print(go())
