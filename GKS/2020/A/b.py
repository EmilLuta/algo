t = int(input())
tc = 1
while t > 0:
    t -= 1
    n, k, p = [int(i) for i in input().split(' ')]
    stacks = []
    sums = []
    for i in range(n):
        stacks.append([int(i) for i in input().split(' ')])
    total = 0
    for i in range(p + 1):
        if n == 1:
            total = sum(stacks[0][:p])
        elif n == 2:
            j = p - i
            total = max(total, sum(stacks[0][:i]) + sum(stacks[1][:j]))
        elif n == 3:
            for j in range(p - i + 1):
                l = p - i - j
                total = max(total, sum(stacks[0][:i]) + sum(stacks[1][:j]) + sum(stacks[2][:l]))
    print('Case #{}: {}'.format(tc, total))
    tc += 1
