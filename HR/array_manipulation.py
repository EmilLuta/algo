n, m = map(int, input().split(' '))

base = 1

while base < n:
    base *= 2

tree = [0] * (base * 2)

def change(i, l, r, q_l, q_r, x):
    if r < q_l or q_r < l:
        return
    if q_l <= l and r <= q_r:
        tree[i] += x
        return
    mid = (l + r) // 2
    change(2 * i, l, mid, q_l, q_r, x)
    change(2 * i + 1, mid + 1, r, q_l, q_r, x)

for i in range(m):
    a, b, k = map(int, input().split(' '))
    a -= 1
    b -= 1
    change(1, 0, base - 1, a, b, k)

output = []

def stuff():
    visited = set()
    parent = [-1] * (base * 2)
    s = [0] * (base * 2)
    s[1] = tree[1]
    queue = [1]
    for item in queue:
        s[item] += tree[item] + s[parent[item]]
        if item >= base:
            continue
        parent[item * 2] = item
        parent[item * 2 + 1] = item
        queue.append(item * 2)
        queue.append(item * 2 + 1)
    return max(s)


print(stuff())
