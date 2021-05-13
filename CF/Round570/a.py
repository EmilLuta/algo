def sum_digits(n):
    s = 0
    for i in str(n):
        s += int(i)
    return s

def go():
    n = int(input())
    x = sum_digits(n)
    while x % 4 != 0:
        n += 1
        x = sum_digits(n)
    return n

print(go())
