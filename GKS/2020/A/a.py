t = int(input())
tc = 1
while t > 0:
    t -= 1
    n, c = [int(i) for i in input().split(' ')]
    h = sorted([int(i) for i in input().split(' ')])
    total = 0
    for i in range(n):
        if c - h[i] >= 0:
            c -= h[i]
            total += 1
            continue
        break
    print(f'Case #{tc}: {total}')
    tc += 1
