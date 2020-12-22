n, m, k = [int(i) for i in input().split(' ')]
for i in range(k):
    input()
    input()
out = ''
for i in range(n - 1):
    out += 'U'
for i in range(m - 1):
    out += 'L'
forward = True
for i in range(n):
    for j in range(m - 1):
        out += 'R' if forward else 'L'
    forward = not forward
    out += 'D'
print(f'{len(out)}\n{out}')
