t = int(input())
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    s = set(a)
    if len(s) > k:
        out += '-1\n'
        continue
    x = ''
    for c in s:
        x += f'{c} '
    for i in range(k - len(s)):
        x += f'1 '
    out += f'{k * n}\n'
    out += f'{(x * n).strip()}\n'
print(out)
