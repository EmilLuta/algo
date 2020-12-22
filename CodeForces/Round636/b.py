t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    if (n // 2) % 2 == 1:
        out += 'NO\n'
        continue
    e = set()
    o = set()
    s_e = 0
    s_o = 0
    for i in range(2, n + 1, 2):
        e.add(i)
        s_e += i
    for i in range(1, n - 1, 2):
        o.add(i)
        s_o += i
    if s_e - s_o in o:
        out += 'NO\n'
        continue
    out += 'YES\n'
    out += ' '.join(str(x) for x in [*e, *o, s_e - s_o])
    out += '\n'
print(out)
