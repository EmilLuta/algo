t = int(input())
tc = 1
while t > 0:
    t -= 1
    init = [int(i) for i in input()]
    up = init[:]
    down = init[:]
    n = len(init)
    i = 0
    found = False
    while i < n:
        if found:
            down[i] = 8
        if down[i] % 2 == 1:
            down[i] -= 1
            found = True
        i += 1
    i = 0
    found = False
    append_two = False
    while i < n:
        if found:
            up[i] = 0
        if up[i] % 2 == 1:
            up[i] = (up[i] + 1) % 10
            if up[i] == 0:
                for j in range(i - 1, -1, -1):
                    up[j] = (up[j] + 2) % 10
                    if up[j] != 0:
                        break
                if up[0] == 0:
                    append_two = True
            found = True
        i += 1
    if append_two:
        up.insert(0, 2)
    init_no = int(''.join(str(d) for d in init))
    up_no = int(''.join(str(d) for d in up))
    down_no = int(''.join(str(d) for d in down))
    print('Case #{}: {}'.format(tc, min(init_no - down_no, up_no - init_no)))
    tc += 1
