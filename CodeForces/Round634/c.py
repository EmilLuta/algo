from collections import Counter, defaultdict

t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    c = Counter(a)
    m = 0
    for key in c:
        m = max(m, c[key])
    x = len(c) - 1
    if x > m:
        out += str(m) + '\n'
    elif x + 1 == m or x == m:
        out += str(x) + '\n'
    else:
        out += str(x + 1) + '\n'
    # import code
    # code.interact(local=dict(globals(), **locals()))
print(out)
