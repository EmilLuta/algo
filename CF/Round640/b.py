t = int(input())
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    if k > n:
        out += 'NO\n'
    elif (n - (k - 1)) > 0 and (n - (k - 1)) % 2 == 1:
        out += 'YES\n'
        out += ' '.join('1' for _ in range(k - 1))
        out += f' {n - (k - 1)}\n'
    elif (n - (k - 1) * 2) > 1 and (n - (k - 1) * 2) % 2 == 0:
        out += 'YES\n'
        out += ' '.join('2' for _ in range(k - 1))
        out += f' {n - (k - 1) * 2}\n'
    else:
        out += 'NO\n'
print(out)
