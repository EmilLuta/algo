
def go():
    n = int(input())
    if n % 2 == 0:
        return n // 2
    a = n
    c = 0
    i = 2
    while i * i <= n:
        if n % i == 0:
            a = i
            break
        i += 1
    n -= a
    return 1 + n // 2
print(go())
