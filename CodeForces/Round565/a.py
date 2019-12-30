def fix(a):
    c = 0
    while a != 1:
        c += 1
        if a % 2 == 0:
            a = a // 2
        elif a % 3 == 0:
            a = 2 * a // 3
        elif a % 5 == 0:
            a = 4 * a // 5
        else:
            return -1
    return c

def go():
    q = int(input())
    o = ''
    for i in range(q):
        o += str(fix(int(input()))) + '\n'
    return o

print(go())
