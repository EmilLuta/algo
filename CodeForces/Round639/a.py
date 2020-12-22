t = int(input())

while t > 0:
    t -= 1
    n, m = [int(i) for i in input().split(' ')]
    if n > m:
        n, m = m, n
    if n == 1:
        print('YES')
    elif n == 2 and m == 2:
        print('YES')
    else:
        print('NO')
