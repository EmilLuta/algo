def add_two_numbers_binary(a, b):
    n = len(a)
    c = [None] * (len(a) + 1)
    d = 0
    for i in range(n):
        d, m = divmod(a[i] + b[i] + d, 2)
        c[i] = m
    c[i + 1] = d
    return c

a = [1, 1, 1]
b = [0, 0, 1]
c = [0, 1, 1, 0, 0, 1, 0, 1]
d = [0, 1, 1, 0, 1, 1, 1, 0]
print(c)
print(d)
print(add_two_numbers_binary(c, d))
print(a)
print(b)
print(add_two_numbers_binary(a, b))
