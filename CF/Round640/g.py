t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    if n < 4:
        out += '-1\n'
        continue
    a = []
    for i in reversed(range(1, n + 1, 2)):
        a.append(i)
    a.append(4)
    a.append(2)
    for i in range(6, n + 1, 2):
        a.append(i)
    out += ' '.join(str(i) for i in a) + '\n'
print(out)
