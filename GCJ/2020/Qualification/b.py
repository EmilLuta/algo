t = int(input())

answer = ''

for tc in range(1, t + 1):
    a = [int(i) for i in input()]
    n = len(a)
    out = ''
    increasing = True
    prev = 0
    for i in range(n):
        if a[i] >= prev:
            increasing = True
        else:
            increasing = False
        if increasing:
            for j in range(prev, a[i]):
                out += '('
        else:
            for j in range(a[i], prev):
                out += ')'
        out += str(a[i])
        prev = a[i]
    for i in range(prev):
        out += ')'
    answer += 'Case #{}: {}\n'.format(tc, out)
print(answer)
