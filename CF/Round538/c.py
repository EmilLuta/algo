from math import factorial

def go():
    n, b = [int(i) for i in input().split(' ')]
    x = factorial(n)
    total = 0
    while True:
        if x % b == 0:
            total += 1
            x //= b
        else:
            break
    return total

print(go())
