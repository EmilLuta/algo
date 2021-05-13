t = int(input())
out = ''
while t > 0:
    t -= 1
    a, b, c, d = [int(i) for i in input().split(' ')]
    left = a - b
    if left <= 0:
        out += f'{b}\n'
        continue
    each = c - d
    if each <= 0:
        out += '-1\n'
        continue
    answer = b + c * (left // each)
    if left % each != 0:
        answer += c
    out += f'{answer}\n'
print(out)
