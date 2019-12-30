t = int(input())
for tc in range(1, t + 1):
    n, k = map(int, input().split(' '))
    c = [int(i) for i in input().split(' ')]
    d = [int(i) for i in input().split(' ')]
    answer = 0
    for i in range(n):
        for j in range(i, n):
            c_max = d_max = 0
            for x in range(i, j + 1):
                c_max = max(c_max, c[x])
                d_max = max(d_max, d[x])
            if abs(c_max - d_max) <= k:
                answer += 1
    print('Case #{}: {}'.format(tc, answer))
