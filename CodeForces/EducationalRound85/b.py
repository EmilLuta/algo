t = int(input())
out = ''
while t > 0:
    t -= 1
    n, x = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    total = s = count = 0
    get_up = []
    for i in range(n):
        if a[i] >= x:
            total += 1
            count += 1
            s += a[i]
        else:
            get_up.append(a[i])
    s -= count * x
    get_up.sort(reverse=True)
    for no in get_up:
        if x - no <= s:
            total += 1
            s -= x - no
            continue
        break
    out += f'{total}\n'
print(out)
