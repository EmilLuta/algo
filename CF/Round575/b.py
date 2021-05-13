t = int(input())

total = ''

for _ in range(t):
    n, k = map(int, input().split(' '))
    a = [int(i) for i in input().split(' ')]
    c = []
    for i in range(n):
        if a[i] % 2 != 0:
            c.append(i + 1)
    if len(c) < k:
        total += 'NO\n'
    else:
        if (len(c) - k) % 2 == 1:
            total += 'NO\n'
        else:
            o = 'YES\n'
            x = c[:k - 1] + [n]
            o += ' '.join(str(i) for i in x)
            o += '\n'
            total += o
print(total)
