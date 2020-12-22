t = int(input())
out = ''
while t > 0:
    t -= 1
    a, b, c, d = [int(i) for i in input().split(' ')]
    if c < a + b:
        out += f'{a} {b} {c}\n'
        continue
    if c < b + b:
        out += f'{b} {b} {c}\n'
        continue
    if d < c + b:
        out += f'{b} {c} {d}\n'
        continue
    if d >= b + c + 1:
        out += f'{b} {c} {b + c + 1}\n'
        continue
print(out)
