from collections import deque

n, q = map(int, input().split(' '))
a = deque(int(i) for i in input().split(' '))
m = max(a)
cache = {}
i = 1
while a[0] != m:
    cache[i] = (a[0], a[1])
    x = a.popleft()
    y = a.popleft()
    if x > y:
        a.appendleft(x)
        a.append(y)
    else:
        a.appendleft(y)
        a.append(x)
    i += 1
o = ''
for _ in range(q):
    query = int(input())
    if query < i:
        o += f'{cache[query][0]} {cache[query][1]}\n'
    else:
        x = query % (n - 1) + n
        o += f'{m} {a[(query - i) % (n - 1) + 1]}\n'
print(o)
