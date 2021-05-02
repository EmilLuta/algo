import math

def lcm(a, b):
    return abs(a*b) // math.gcd(a, b)

n = int(input())
# for n in range(3, m + 1):
print(f"for n = {n} we got:")
for i in range(1, n // 2 + 2):
    for j in range(i, n // 2 + 2):
        for k in range(j, n // 2 + 2):
            if (i + j + k == n and lcm(i, lcm(j, k)) <= n // 2):
                print(i, j, k)
