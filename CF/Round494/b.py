def go():
    a, b, x = [int(i) for i in input().split(' ')]
    prev = '1'  if a > b else '0'
    o = ''
    if x == 1:
        return '0' * a + '1' * b
    i = 0
    while i < a + b:
        if x:
            if prev == '0':
                o += '1'
                b -= 1
                prev = '1'
            else:
                o += '0'
                a -= 1
                prev = '0'
            x -= 1
        else:
            if prev == '1':
                o += '1' * b
                b = 0
                prev = '0'
            else:
                o += '0' * a
                a = 0
                prev = '1'
    return o

print(go())
