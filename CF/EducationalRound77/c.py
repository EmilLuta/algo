n = 10000

# for r in range(5, 30):
    # for b in range(r + 1, 30):
r = 4
b = 6
a = ['x'] * n
for i in range(n):
    if i % r == 0 and i % b == 0:
        a[i] = 'c'
    elif i % r == 0:
        a[i] = 'r'
    elif i % b == 0:
        a[i] = 'b'

x = [i for i in a if i != 'x']

import code
code.interact(local=dict(globals(), **locals()))
