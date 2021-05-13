for i in range(1, 100):
    diff = 1
    a = i
    b = i
    while a > 0 and b > 0:
        a = a - 2 * diff
        b = b - diff
        a, b = b, a
    print(f" for {i} we got {a}, {b}")

