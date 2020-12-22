def multiply(x, y):
    if x % 10 == x or y % 10 == y:
        return x * y
    n = max(len(str(x)), len(str(y)))
    m = n // 2
    a = x // 10 ** m
    b = x % 10 ** m
    c = y // 10 ** m
    d = y % 10 ** m
    ac = multiply(a, c)
    bd = multiply(b, d)
    ad_plus_bc = multiply(a + b, c + d) - ac - bd
    return ac * 10 ** (2 * m) + ad_plus_bc * (10 ** m) + bd


x = 3141592653589793238462643383279502884197169399375105820974944592
y = 2718281828459045235360287471352662497757247093699959574966967627

assert multiply(x, y) == x * y
print(multiply(x, y))
