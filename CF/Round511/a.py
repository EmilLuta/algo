def go():
    n = int(input())
    a = 1
    b = 1
    c = n - 2
    while a % 3 == 0 or b % 3 == 0 or c % 3 == 0:
        if c % 3 == 0:
            c -= 1
            b += 1
        elif b % 3 == 0:
            b -= 1
            a += 1
        else:
            a -= 1
            if (c + 1) % 3 == 0:
                b += 1
            else:
                c += 1
    return '{} {} {}'.format(a, b, c)
print(go())
