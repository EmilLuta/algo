def go():
    m = 10 ** 6
    m_sq = m ** 2
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    sieve = [True] * (m)
    for i in range(2, m):
        if sieve[i] == True:
            for j in range(i ** 2, m, i):
                sieve[j] = False
    s = set(i for i in range(2, m) if sieve[i])
    o = ''
    from math import sqrt
    for i in a:
        sq = sqrt(i)
        if int(sq) == sq:
            if sq in s:
                o += 'YES\n'
            else:
                o += 'NO\n'
        else:
            o += 'NO\n'
    return o

print(go())
