t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    s = 3
    w = 1
    while n % s != 0:
        w += 1
        s += 2 ** w
    out += f'{n // s}\n'
print(out)
