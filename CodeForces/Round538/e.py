from sys import stdout
from math import gcd

def go():
    n = int(input())
    q = 57
    print("? 0")
    stdout.flush()
    a = int(input())
    print("? 1")
    stdout.flush()
    b = int(input())
    if n == 2:
        print("! {} {}".format(min(a, b), max(a, b) - min(a, b)))
    print("? 1")
    stdout.flush()
    c = int(input())
    x = [a, b, c]
    x.sort()
    one = gcd(x[0], x[1])
    two = gcd(x[1], x[2])
    while True:


print(go())
