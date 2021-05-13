def go():
    n, b = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]

    odd = 0
    even = 0
    cuts = []
    for i in range(n - 1):
        if a[i] % 2 == 1:
            odd += 1
        else:
            even += 1
        if odd == even:
            cost = abs(a[i] - a[i + 1])
            if cost <= b:
                cuts.append(cost)
                odd = 0
                even = 0
    cuts = sorted(cuts)
    total = 0
    current = 0
    i = 0
    while current <= b and i < len(cuts):
        current += cuts[i]
        total += 1
        i += 1
    if current > b:
        total -= 1
    return total

print(go())
