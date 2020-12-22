import code
import sys
from random import randrange

file_name = sys.argv[1]

with open(file_name, 'r') as f:
    k, n = [int(i) for i in f.readline().split(' ')]
    p = [int(i) for i in f.readline().split(' ')]

curr = k
left = set()
output = set()
for i in range(n - 1, -1, -1):
    if p[i] <= curr:
        output.add(i)
        curr -= p[i]
    else:
        left.add(i)
output = list(output)
initial = curr
print(f'initial max {initial}')
for _ in range(10000):
    o_i = randrange(0, len(output))
    curr += p[output[o_i]]
    buff = []
    for i in left:
        if p[i] <= curr:
            curr -= p[i]
            buff.append(i)
    if curr < initial:
        for i in buff:
            output.append(i)
            left.remove(i)
        output.pop(o_i)
        initial = curr
    else:
        for i in buff:
            curr += p[i]
        curr -= p[output[o_i]]

with open(f'{file_name[0]}.out', 'w+') as f:
    assert len(output) == len(set(output))
    assert sum(p[i] for i in output) <= k
    f.write(str(len(output)) + '\n')
    o = ' '.join([str(i) for i in output])
    f.write(o)
print(f'final max {curr}')
code.interact(local=dict(globals(), **locals()))
