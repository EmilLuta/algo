from random import randint

n = 300000
o = []
taken = set()
while len(taken) != n:
    x = randint(1, n)
    if x not in taken:
        taken.add(x)
        o.append(x)
with open('f', 'w+') as f:
    f.write(str(n) + '\n')
    f.write(' '.join(str(i) for i in o))
