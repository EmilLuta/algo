def go():
    MOD = 998244353
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    c = [None] * n
    b = sorted([int(i) for i in input().split(' ')], reverse=True)
    for i in range(n):
        a[i] = a[i] * (n - i) * (i + 1)
    a.sort()
    total = 0
    for i in range(n):
        total = (total + a[i] * b[i]) % MOD
    return total

print(go())
