out = ''
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    a = 2 ** n
    b = 0
    for i in range(1, n // 2):
        a += 2 ** i
    for i in range(n // 2, n):
        b += 2 ** i
    out += f'{a - b}\n'
print(out)
