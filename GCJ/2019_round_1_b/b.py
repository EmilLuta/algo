t, w = map(int, input().split(' '))
for test_case in range(t):
    days = [None, 0, 0, 0, 0, 0, 0]
    for i in range(1, w + 1):
        print(i)
        days[i] = int(input())
    b = days[2] - days[1]
    c = days[3] - days[2]
    d = (days[4] - days[3]) - 2 * b
    e = days[5] - days[4]
    f = (days[6] - days[5]) - 4 * b - 2 * c
    a = ((b + c + d + e + f) - days[1]) // 40
    b = b - 2 * a
    c = c - 4 * a
    d = d - 4 * a
    e = e - 16 * a
    f = f - 16 * a
    print('{} {} {} {} {} {}'.format(a, b, c, d, e, f))
    assert int(input()) == 1
