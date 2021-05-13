t = int(input())

while t > 0:
    t -= 1
    a = input()
    n = len(a)
    s = pl = mi = 0
    m = {}
    for i in range(n):
        if a[i] == '+':
            pl += 1
            s += 1
        else:
            mi += 1
            s -= 1
        if s < 0 and s not in m:
            m[s] = i + 1
    if pl >= mi:
        print(n)
        break
    answer = 0
    for i in range(pl - mi, 0):
        answer += m[i]
    print(answer + n)
