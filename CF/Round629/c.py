t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = ''
    b = ''
    big_a = False
    for c in input():
        if c == '2':
            if big_a:
                a += '0'
                b += '2'
                continue
            a += '1'
            b += '1'
        elif c == '1':
            if not big_a:
                a += '1'
                b += '0'
                big_a = True
                continue
            a += '0'
            b += '1'
        else:
            a += '0'
            b += '0'
    out += f'{a}\n{b}\n'
print(out)
