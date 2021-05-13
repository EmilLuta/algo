MOD = 998244353
r, c = [int(i) for i in input().split(' ')]
x = 1
while r != 0:
    x = (2 * x) % MOD
    r -= 1
while c != 0:
    x = (2 * x) % MOD
    c -= 1
print(x)
