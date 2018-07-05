def go():
    n, m = [int(i) for i in input().split(' ')]
    v = []
    for i in range(m):
        v.append([int(i) - 1 for i in input().split(' ')])
    v = sorted(v, key=lambda x: x[1] - x[0], reverse=True)
    a = ['.'] * n
    for i in v:
        ones = 0
        zeros = 0
        for j in range(i[0], i[1] + 1):
            if a[j] == '1':
                ones += 1
            elif a[j] == '0':
                zeros += 1
        if zeros > ones:
            first = '1'
            second = '0'
        else:
            first = '0'
            second = '1'
        for j in range(i[0], i[0] + (i[1] - i[0]) // 2 + 1):
            if a[j] == '.':
                a[j] = first
        for j in range(i[0] + (i[1] - i[0]) // 2 + 1, i[1] + 1):
            if a[j] == '.':
                a[j] = second
    return ''.join(a)

print(go())
