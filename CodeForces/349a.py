def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    s = m = 0
    for i in a:
        if i == 25:
            s += 1
        elif i == 50:
            if s >= 1:
                s -= 1
                m += 1
            else:
                return 'NO'
        elif i == 100:
            if s >= 1 and m >= 1:
                s -= 1
                m -= 1
            elif s >= 3:
                s -= 3
            else:
                return 'NO'
    return 'YES'

print(go())
