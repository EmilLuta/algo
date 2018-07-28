from collections import Counter

def go():
    n = int(input())
    c = Counter([int(i) for i in input().split(' ')])
    o = ''
    if len(c) < 3 or 5 in c or 7 in c:
        return -1
    while len(c) > 2:
        forward = False
        if 1 in c and 2 in c and 4 in c:
            o += '1 2 4\n'
            if c[1] == 1:
                c.pop(1)
            else:
                c[1] -= 1

            if c[2] == 1:
                c.pop(2)
            else:
                c[2] -= 1

            if c[4] == 1:
                c.pop(4)
            else:
                c[4] -= 1
            forward = True
        elif 1 in c and 2 in c and 6 in c:
            o += '1 2 6\n'
            if c[1] == 1:
                c.pop(1)
            else:
                c[1] -= 1

            if c[2] == 1:
                c.pop(2)
            else:
                c[2] -= 1

            if c[6] == 1:
                c.pop(6)
            else:
                c[6] -= 1
            forward = True
        elif 1 in c and 3 in c and 6 in c:
            o += '1 3 6\n'
            if c[1] == 1:
                c.pop(1)
            else:
                c[1] -= 1

            if c[3] == 1:
                c.pop(3)
            else:
                c[3] -= 1

            if c[6] == 1:
                c.pop(6)
            else:
                c[6] -= 1
            forward = True
        if not forward:
            break
    if len(c) != 0:
        return -1
    return o

print(go())
