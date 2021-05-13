t = int(input())

out = ''

while t > 0:
    t -= 1
    n = int(input())
    n -= 1
    n //= 2
    out += str(n) + '\n'
print(out)
