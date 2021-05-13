from string import ascii_lowercase

t = int(input())

out = ''

while t > 0:
    t -= 1
    n, a, b  = [int(i) for i in input().split(' ')]
    usage = ascii_lowercase[:b]
    usage = (('a' * (a - b) + usage) * (n // a + 1))[:n]
    out += usage + '\n'
print(out)
