def go():
    a, b, c = [int(i) for i in input().split(' ')]
    x = 0
    while True:
        if a + b > c:
            if b + c > a:
                if a + c > b:
                    return x
        if a <= b and a <= c:
            a += 1
        elif b <= a and b <= c:
            b += 1
        elif c <= a and c <= b:
            c += 1
        x += 1

print(go())
