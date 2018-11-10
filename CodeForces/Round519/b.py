def go():
    n = int(input())
    a = [0] + [int(i) for i in input().split(' ')]
    k = []
    o = []
    for i in range(n):
        k.append(a[i + 1] - a[i])
    # s_n_k = len(set(k))v
    # if s_n_k == n:
    #     print(1)
    #     print(n)
    # elif s_n_k == 1:
    #     print(n)
    #     print(' '.join(str(i) for i in range(1, n + 1)))
    # else:
    for i in range(1, len(k)):
        for j in range(0, len(k) - i):
            if k[j] != k[j + i]:
                break
        else:
            o.append(i)
    o.append(n)
    print(len(o))
    print(' '.join(str(i) for i in o))
go()
