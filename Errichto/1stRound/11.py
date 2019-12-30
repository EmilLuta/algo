# implement the segment tree
# "1 i x" - change a[i] to x
# "2 L R" - print the maximum in interval [L, R]

# n, q = [int(i) for i in input().split(' ')]
# a = [int(i) for i in input().split(' ')]

# base = 1
# while base < n:
#     base *= 2

# t = [None] * (base * 2)

# for i in range(n):
#     t[base + i] = a[i]
# for i in range(base - 1, 0, -1):
#     t[i] = max(t[i * 2], t[i * 2 + 1])

# def change(i, x):
#     t[base + i] = x
#     p = (base + i) // 2
#     while p >= 1:
#         t[p] = max(t[p * 2], t[p * 2 + 1])
#         p //= 2

# m = float('-inf')

# def max_interval(i, l, r, q_l, q_r):
#     global m
#     if r < q_l or q_r < l:
#         return
#     if q_l <= l and r <= q_r:
#         m = max(t[i], m)
#         return
#     mid = (l + r) // 2
#     max_interval(2 * i, l, mid, q_l, q_r)
#     max_interval(2 * i + 1, mid + 1, r, q_l, q_r)

# for _ in range(q):
#     option, index, value = [int(i) for i in input().split(' ')]
#     if option == 1:
#         change(index, value)
#     else:
#         m = float('-inf')
#         max_interval(1, 0, base - 1, index, value)
#         print(m)

# a tree of type interval-point
# much harder: interval-interval trees --- solvable with lazy propagation

# 3) "1 L R x" - for i in range(L, R+1): a[i] += x
# "2 i" - print a[i]
# n, q = [int(i) for i in input().split(' ')]
# a = [int(i) for i in input().split(' ')]

# base = 1
# while base < n:
#     base *= 2

# t = [0] * (base * 2)

# for i in range(n):
#     t[base + i] = a[i]

# def change(i, l, r, q_l, q_r, x):
#     if r < q_l or q_r < l:
#         return
#     if q_l <= l and r <= q_r:
#         t[i] += x
#         return
#     mid = (l + r) // 2
#     change(2 * i, l, mid, q_l, q_r, x)
#     change(2 * i + 1, mid + 1, r, q_l, q_r, x)

# def query(i):
#     value = t[base + i]
#     p = (base + i) // 2
#     while p >= 1:
#         value += t[p]
#         p //= 2
#     print(value)

# for _ in range(q):
#     options = [int(i) for i in input().split(' ')]
#     if options[0] == 1:
#         change(1, 0, base - 1, options[1], options[2], options[3])
#     else:
#         query(options[1])

# 3*) "1 L R x" - change everything in interval [L, R] to x
# "2 i" - print a[i]

n, q = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

base = 1
while base < n:
    base *= 2

t = [(0, 0)] * (base * 2)

for i in range(n):
    t[base + i] = (a[i], 0)

def change(i, l, r, q_l, q_r, v, x):
    if r < q_l or q_r < l:
        return
    if q_l <= l and r <= q_r:
        t[i] = (v, x)
        return
    mid = (l + r) // 2
    change(2 * i, l, mid, q_l, q_r, v, x)
    change(2 * i + 1, mid + 1, r, q_l, q_r, v, x)

def query(i):
    value = t[base + i][0]
    x = t[base + i][1]
    p = (base + i) // 2
    while p >= 1:
        if x < t[p][1]:
            value = t[p][0]
            x = t[p][1]
        p //= 2
    print(value)

for x in range(q):
    options = [int(i) for i in input().split(' ')]
    if options[0] == 1:
        change(1, 0, base - 1, options[1], options[2], options[3], x)
    else:
        query(options[1])

