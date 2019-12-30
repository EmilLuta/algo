""" Homework
1) Given a sequence of non-negative numbers, N <= 10^5,
    find the number of intervals with product equal to 0.
[2, 3, 0, 4, 0, 0, 1]

2) Think about a tree that answers queries:
"1 L R x" - for every i in interval [L, R], change a[i] to x
"2 i" - print a[i]

2a) implement your version with (x, last_time)
2b) implement a version with (x) only (avoid double memory)

3) implement gcd problem from scratch (well, you can cheat a little bit and take my code)

4*) implement sum-of-maxima with double-linked list
"""


# 1)
n = int(input())
a = [int(i) for i in input().split(' ')]

t = 0
prev_i = 0
for i in range(n):
    if a[i] == 0:
        t += (i + 1 - prev_i) * (n - i)
        prev_i = i + 1
print(t)

# 2a)
n, q = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

base = 1
while base < n:
    base *= 2

tree = []

for i in range(base * 2):
    tree.append([0, 0])

for i in range(n):
    tree[base + i] = [a[i], 0]

def change(i, l, r, q_l, q_r, value, index):
    if r < q_l or q_r < l:
        return
    if q_l <= l and r <= q_r:
        tree[i] = [value, k]
        return
    mid = (l + r) // 2
    change(2 * i, l, mid, q_l, q_r, value, index)
    change(2 * i + 1, mid + 1, r, q_l, q_r, value, index)

def query(i):
    value = tree[base + i][0]
    current_level = tree[base + i][1]
    node = (base + i) // 2
    while node >= 1:
        if tree[node][1] > current_level:
            current_level = tree[node][1]
            value = tree[node][0]
        node //= 2
    print(value)

for k in range(q):
    x = [int(i) for i in input().split(' ')]
    if x[0] == 1:
        change(1, 0, base - 1, x[1], x[2], x[3], k)
    if x[0] == 2:
       query(x[1])

# 4)
n = int(input())
a = [n + 1] + [int(i) for i in input().split(' ')] + [n + 1]

where = [None] * (n + 2)
next_l = [n + 1] * (n + 2)
prev_l = [n + 1] * (n + 2)

for i in range(1, n + 1):
    where[a[i]] = i
    next_l[i] = i + 1
    prev_l[i] = i - 1

a = 0
for x in range(1, n + 1):
    i = where[x]
    r = next_l[i] - i
    l = i - prev_l[i]
    a += r * l * x
    next_l[prev_l[i]] = next_l[i]
    prev_l[next_l[i]] = prev_l[i]

print(a)
