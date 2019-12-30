# Given an sequence of positive numbers, find the sum of gcd's of all intervals
from math import gcd as math_gcd

def gcd(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    return math_gcd(a, b)

n = int(input())
a = [int(i) for i in input().split(' ')]

answer = 0

pre = [None] * n
pre[0] = a[0]
for i in range(1, n):
    pre[i] = gcd(a[i], pre[i - 1])

for L in range(n):
    for R in range(L, n):
        # the part below is just O(N + log(10^9))
        g = a[L]
        for i in range(L + 1, R + 1):
            g = gcd(g, a[i]) # O(log(10^9))
        answer += g
print(answer)

# SK8ER BOI

s = 0
for i in range(n):
    x = a[i]
    s += x
    for j in range(i + 1, n):
        x = gcd(x, a[j])
        s += x

print(s)

# CREATE A GCD TREE
# PARSE IT TO GET DATA

base = 1
while base < n:
    base *= 2

total = 0

t = [0] * (base * 2)

for i in range(n):
    t[base + i] = a[i]
    total += a[i]

for i in range(base - 1, 0, -1):
    t[i] = gcd(t[i * 2], t[i * 2 + 1])
    total += t[i]
print(total)
