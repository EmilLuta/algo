def products(a):
    o = [1] * len(a)
    x = 1
    for i in range(1, len(a)):
        x *= a[i - 1]
        o[i] *= x
    print(o)
    x = 1
    for i in range(len(a) - 2, -1, -1):
        x *= a[i + 1]
        o[i] *= x
    return o
