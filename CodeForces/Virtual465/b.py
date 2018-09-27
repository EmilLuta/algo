def go():
    n = int(input())
    total = 0
    x = 0
    y = 0
    k = 0
    d = input()
    if d[0] == 'U':
        k = 1
        y += 1
    else:
        k = 2
        x += 1

    for i in d[1:]:
        if x == y:
            if i == 'U' and k == 2:
                total += 1
                k = 1
            elif i == 'R' and k == 1:
                total += 1
                k = 2
        if i == 'U':
            y += 1
        else:
            x += 1
    return total

print(go())
