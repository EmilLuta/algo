from collections import Counter

def go():
    s = input()
    t = input()
    p = input()
    n = len(s)
    m = len(t)
    i = 0
    j = 0
    while i < n:
        while j < m and s[i] != t[j]:
            j += 1
        if j == m:
            return 'NO'
        i += 1
        j += 1
    if i != n:
        return 'NO'
    c1 = Counter(t)
    c2 = Counter(s + p)
    for key in c1:
        if key not in c2 or c1[key] > c2[key]:
            return 'NO'
    return 'YES'

o = ''
q = int(input())
for _ in range(q):
    o += f'{go()}\n'
print(o)
