n = int(input())
a = [int(i) for i in input().split(' ')]
q = int(input())
base = 1
while base < n:
    base *= 2

tree = [-1] * (base * 2)
for i in range(n):
    tree[base + i] = a[i]


def change(index):
    if index >= base:
        return
    if index > 1:
        change(index // 2)
    # print('puta')
    # import code
    # code.interact(local=dict(globals(), **locals()))
    tree[index * 2] = max(tree[index], tree[index * 2])
    tree[index * 2 + 1] = max(tree[index], tree[index * 2 + 1])
    tree[index] = -1
    # print('madre')
    # import code
    # code.interact(local=dict(globals(), **locals()))

for _ in range(q):
    data = [int(i) for i in input().split(' ')]
    if data[0] == 2:
        tree[1] = max(data[1], tree[1])
    else:
        change((base + data[1] - 1) // 2)
        # import code
        # code.interact(local=dict(globals(), **locals()))
        tree[base + data[1] - 1] = data[2]
    # import code
    # code.interact(local=dict(globals(), **locals()))
o = []
for i in range(base, base + n):
    m = 0
    index = i
    while index > 0:
        m = max(tree[index], m)
        index //= 2
    o.append(str(m))
print(' '.join(o))
