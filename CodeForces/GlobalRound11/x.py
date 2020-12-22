from random import randint

r = 500
n = 100000

with open('t.in', 'w+') as f:
    f.write(f'{r} {n}\n')
    for i in range(n):
        f.write(f'{i * 10 + 10} {randint(1, r + 1)} {randint(1, r + 1)}\n')
