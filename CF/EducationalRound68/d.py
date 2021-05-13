def go():
    n, k = [int(i) for i in input().split(' ')]
    if k % 3 == 0:
        x = n % (k + 1)
        if x % 3 == 0 and x != k:
            return 'Bob'
    else:
        x = n % 3
        if x == 0:
            return 'Bob'
    return 'Alice'

t = int(input())

o = ''

for _ in range(t):
    o += f'{go()}\n'
print(o)
