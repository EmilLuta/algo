import heapq
from collections import Counter
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    c = Counter([int(i) for i in input().split(' ')])
    answer = left = 0
    sorted_keys = sorted(c.keys())
    h = []
    for key in sorted_keys:
        mod = c[key] % c
        if mod != 0:
            h.append((c[key] % c, key))
        # diffs[c[key] % c].append(key)
    # sorted_diffs = sorted(diffs.keys())
    heapq.heapify(h)
    for key in sorted_keys:
        while True:
            if len(h) == 0:
                break
            need, value = h[0]
            if need <= c[key] and need < key and value > key:
                answer += 1
                c[key] -= need
                heapq.heappop(h)
                continue
            break
        
    print(answer)
