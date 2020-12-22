from itertools import product
m=3
n=2

x = [[list(i[x:x+m]) for x in range(0, len(i), m)] for i in product("ABCDE", repeat=m*n)]
for i in x:
    for r in i:
        print(r)
    print('===')
