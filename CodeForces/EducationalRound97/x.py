from itertools import permutations

t = int(input())

for i in range(t):
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    x = [i + 1 for i in range(n)]
    answer = float('inf')
    for p in permutations(x):
        c = 0
        for i in range(n):
            c += abs(a[i] - p[i])
        answer = min(answer, c)
    print(answer)
