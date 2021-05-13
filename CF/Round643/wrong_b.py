import heapq

from collections import Counter
from math import sqrt
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    c = Counter([int(i) for i in input().split(' ')])
    h = []
    answer = 0
    left = {}
    for i in range(1, n):
        if i in c:
            if c[i] - i >= 0:
                left[i] = c[i] - i
                answer += 1
            else:
                h.append((i - c[i], i))
        else:
            h.append((i, i))
    if len(left) == 0:
        print(answer)
        continue
    heapq.heapify(h)
    left_now = 0
    item = heapq.heappop(h)
    for key in sorted(left.keys()):
        left_now += left[key]
        while key > item[1]:
            item = heapq.heappop(h)
        if item[0] > left_now:
            continue
        answer += 1
        left_now -= item[0]
    print(answer)
