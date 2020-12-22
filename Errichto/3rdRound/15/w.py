from random import randint, choice
from string import ascii_lowercase

out = []
for i in range(100000):
    length = randint(1, 6)
    x = ''
    for i in range(length):
        x += choice(ascii_lowercase)
    out.append(x)
with open('in.txt', 'w+') as f:
    f.write(f'{len(out)}\n')
    for z in out:
        f.write(f'{z}\n')
