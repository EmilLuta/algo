t = int(input())
out = ''
while t > 0:
    t -= 1
    n, m = [int(i) for i in input().split(' ')]
    for i in range(n - 1):
        out += 'B' + (m - 1) * 'W' + '\n'
    out += m * 'B' + '\n'
print(out)
