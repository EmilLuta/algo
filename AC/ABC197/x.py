a = [int(i) for i in input().split(' ')]
result = []

def go(l, current_config, started, i):
    if i == len(l):
        current_config.append(started)
        result.append(current_config)
        return
    cc = current_config[:]
    cc.append(started[:])
    go(l, cc, [l[i]], i + 1)
    go(l, current_config[:], started[:] + [l[i]], i + 1)


go(a, [], [a[0]], 1)
print(len(result))
answer = float('inf')
for i in result:
    xor_eq = 0
    for x in i:
        or_eq = 0
        for w in x:
            or_eq = or_eq | w
        xor_eq = xor_eq ^ or_eq
    answer = min(answer, xor_eq)
print(answer)
