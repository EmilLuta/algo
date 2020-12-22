t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    if len(a) == 1:
        out += f'{a[0]}\n'
        continue
    b = []
    i = 1
    answer = a[0]
    while i < n:
        if (a[i] < 0 and a[i - 1] < 0) or (a[i] > 0 and a[i - 1] > 0):
            answer = max(answer, a[i])
        else:
            b.append(answer)
            answer = a[i]
        i += 1
    b.append(answer)
    out += f'{sum(b)}\n'
print(out)
