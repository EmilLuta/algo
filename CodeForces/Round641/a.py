t = int(input())
m = 10 ** 6 + 5
sieve = [m] * m
sieve[1] = sieve[0] = 1
for i in range(2, m):
    if sieve[i] == m:
        for j in range(i * 2, m, i):
            sieve[j] = min(sieve[j], i)
        sieve[i] = i
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    out += str(n + sieve[n] + 2 * (k - 1)) + '\n'
print(out)
