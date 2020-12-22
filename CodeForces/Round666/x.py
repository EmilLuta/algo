# a = [1, 100000, 100000, 100000, 100000, 100000, 100000, 100000000]
a = [1000000000, 1000000000, 1000000000]
# a = [1, 4, 16, 64, 256, 65536]
n = len(a)
# n = int(input())
# a = [int(i) for i in input().split(' ')]
# from random import randint
# n = 10 ** 5
# a = [randint(1, 10 ** 9) for _ in range(n)]
good = float('inf')
goob_b = -1
for b in range(1000000):
    current = 0
    for i in range(n):
        current += abs(a[i] - b ** i)
    if good > abs(current):
        good = abs(current)
        good_b = b
    # print(f'for base = {b} we get answer = {current}')
print(f'base = {good_b}, answer = {good}, sum = {sum(a)}')
