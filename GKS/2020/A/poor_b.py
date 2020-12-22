import heapq

t = int(input())
tc = 1
while t > 0:
    t -= 1
    n, k, p = [int(i) for i in input().split(' ')]
    stacks = []
    for i in range(n):
        stacks.append([int(i) for i in input().split(' ')])
    h = [(-stacks[i][0], i, 0) for i in range(n)]
    heapq.heapify(h)
    total = 0
    while p > 0:
        p -= 1
        value, s_i, i = heapq.heappop(h)
        value = -value
        total += value
        if i + 1 < k:
            heapq.heappush(h, (-stacks[s_i][i + 1], s_i, i + 1))
    print('Case #{}: {}'.format(tc, total))
    tc += 1
