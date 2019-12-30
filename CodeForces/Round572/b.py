def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    a.sort()
    o = []
    aux = []
    for i in range(n):
        if i % 2 == 0:
            o.append(a[i])
        else:
            aux.append(a[i])
    o.extend(reversed(aux))
    for i in range(-1, n - 1):
        if o[i - 1] + o[i + 1] <= o[i]:
            return 'NO'
    return 'YES\n{}'.format(' '.join([str(i) for i in o]))

print(go())
