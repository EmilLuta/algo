t = int(input())

o = ''

for _ in range(t):
    n = int(input())
    s = [i for i in input()]
    if '1' not in s:
        o += f'{n}\n'
    else:
        index_1 = s.index('1')
        s.reverse()
        index_2 = s.index('1')
        # import code
        # code.interact(local=dict(globals(), **locals()))
        # x = 
        o += f'{2 + max(2 * max(n - index_1 - 1, index_1), 2 * max(n - index_2 - 1, index_2))}\n'
print(o)
