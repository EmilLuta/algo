n = int(input())
for i in range(n):
    a = input()
    x = ''
    y = ''
    for j in range(len(a)):
        if a[j] == '4':
            x += '2'
            y += '2'
        else:
            x += a[j]
            y += '0'
    print('Case #{}: {} {}'.format(i + 1, x, int(y)))
