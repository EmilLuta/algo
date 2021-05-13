def go():
    n, m, l = [int(i) for i in input().split(' ')]
    a = [-1] + [int(i) for i in input().split(' ')] + [-1]
    o = ''
    c = 0
    for i in range(1, n + 1):
        if a[i] > l:
            if a[i - 1] <= l:
                c += 1

    for i in range(m):
        x = [int(j) for j in input().split(' ')]
        if x[0] == 0:
            o += str(c) + '\n'
        else:
            if a[x[1]] > l:
                continue
            a[x[1]] += x[2]
            if a[x[1]] > l:
                if a[x[1] - 1] > l and a[x[1] + 1] > l:
                    c -= 1
                elif a[x[1] - 1] <= l and a[x[1] + 1] <= l:
                    c += 1

    return o
print(go())




