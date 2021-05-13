from collections import Counter
from string import ascii_lowercase
t = int(input())
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    a = input()
    m = len(ascii_lowercase)
    count = [0] * m
    diff = 0
    for c in a:
        count[c - 'a'] += 1
        if count[c - 'a'] == 1:
            diff += 1
    found = None
    for i in range(m):
        if count[i] >= k:
            found = chr(ord('a') + i)
            break
    if found is None:
        if k == 1:
            out += f'{\'\'.join(sorted(a))}\n'
            continue
        if diff == 1:
            if n % k == 0:
                for i in range(n)
                out += f'{
            continue
        for i in range(m):
            if count[i] > 0:
                out += f'{chr(ord(\'a\'a) + i}\n'
