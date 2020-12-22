n = int(input())

# a = [i for i in range(n * 2)]

a = [(int(x), i) for (i, x) in enumerate(input().split(' '))]

from itertools import permutations
from string import ascii_lowercase

mid = n

seen = set()

answer = 0

from collections import defaultdict

d = defaultdict(int)

for perm in permutations(a):
    x = sorted(perm[:mid])
    y = sorted(perm[mid:], reverse=True)
    identity = (tuple(x), tuple(y))
    if identity not in seen:
        seen.add(identity)
        for i in range(n):
            f = x[i][0]
            g = y[i][0]
            if f > g:
                f, g = g, f
            # d[f'{ascii_lowercase[f]} - {ascii_lowercase[g]}'] += 1
            answer += g - f
# for k in d:
    # print(f'{k} => {d[k]}')
print(answer)
# print(seen)
