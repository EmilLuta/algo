t = int(input())
tc = 1
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    # while k > 0:
    diff = -1
    d_i = -1
    for i in range(1, n):
        d = a[i] - a[i - 1]
        if d > diff:
            diff = d
            d_i = i
    if diff == 1:
        a.append(a[-1] + 1)
    elif diff % 2 == 0:
        diff //= 2
        a.insert(d_i, a[d_i] - diff)
    else:
        diff = (diff + 1) // 2
        a.insert(d_i, a[d_i] - diff)
    # k -= 1
    # import code
    # code.interact(local=dict(globals(), **locals()))
    diff = -1
    for i in range(1, len(a)):
        diff = max(diff, a[i] - a[i - 1])
        # print(f'{a[i]} - {a[i] - 1} == {a[i] - a[i - 1]}')
    print('Case #{}: {}'.format(tc, diff))
    tc += 1
