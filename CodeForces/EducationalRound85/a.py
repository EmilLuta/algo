t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    prev_p = prev_c = 0
    good = True
    ok_plays = 0
    for i in range(n):
        p, c = [int(i) for i in input().split(' ')]
        if c > p:
            good = False
        if c - prev_c > p - prev_p:
            good = False
        if c < prev_c:
            good = False
        if p < prev_p:
            good = False
        prev_p = p
        prev_c = c
    if good:
        out += 'YES\n'
        continue
    out += 'NO\n'
print(out)
