t = int(input())

while t > 0:
    t -= 1
    a, b = [int(i) for i in input().split(' ')]
    if a < b:
        a, b = b, a
    aa = bin(a).replace('0b', '')
    bb = bin(b).replace('0b', '')
    ok = True
    start = 0
    for i in range(start, len(bb)):
        if aa[i] != bb[i]:
            ok = False
            break
    if not ok:
        print(-1)
        continue
    ok = True
    for i in range(len(bb), len(aa)):
        if aa[i] == '1':
            ok = False
            break
    if not ok:
        print(-1)
        continue
    to_cover = len(aa) - len(bb)
    answer = 0
    for i in range(3, 0, -1):
        answer += to_cover // i
        to_cover %= i
    print(answer)
