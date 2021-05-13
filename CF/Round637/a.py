t = int(input())
out = ''
while t > 0:
    t -= 1
    n, a, b, c, d = [int(i) for i in input().split(' ')]
    found = False
    for i in range(a - b, a + b + 1):
        if i * n >= c - d and i * n <= c + d:
            found = True
            break
    if found:
        out += f'Yes\n'
    else:
        out += f'No\n'
print(out)
