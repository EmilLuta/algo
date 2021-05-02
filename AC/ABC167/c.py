n, m, x = [int(i) for i in input().split(' ')]

from itertools import combinations
a = []
for i in range(n):
    a.append([int(i) for i in input().split(' ')])
min_cost = float('inf')
for i in range(1, n + 1):
    for opt in combinations(range(n), i):
        curr_cost = 0
        curr_skills = [0] * m
        for to_take in opt:
            curr_cost += a[to_take][0]
            for j in range(1, m + 1):
                curr_skills[j - 1] += a[to_take][j]
        found = True
        for j in range(m):
            if curr_skills[j] < x:
                found = False
        if found:
            min_cost = min(min_cost, curr_cost)
print(min_cost if min_cost != float('inf') else -1)
