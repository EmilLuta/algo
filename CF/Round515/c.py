def go():
    n = int(input())
    r = 1
    l = -1
    _, i = input().split(' ')
    k = {i: 0}
    for i in range(n - 1):
        position, i = input().split(' ')
        if position == 'R':
            k[i] = r
            r += 1
        elif position == 'L':
            k[i] = l
            l -= 1
        else:
            print(min(-(l + 1) + k[i], r - k[i] - 1))
    return

go()
