t = int(input())

out = ''

while t > 0:
    t -= 1
    n = int(input())
    free = set([i for i in range(1, n + 1)])
    daughters = []
    for d in range(n):
        info = [int(i) for i in input().split(' ')]
        found = False
        for i in range(1, info[0] + 1):
            if info[i] in free:
                free.remove(info[i])
                found = True
                break
        if not found:
            daughters.append(d + 1)
    if len(daughters) == 0:
        out += 'OPTIMAL\n'
        continue
    out += f'IMPROVE\n{daughters[0]} {free.pop()}\n'
print(out)


