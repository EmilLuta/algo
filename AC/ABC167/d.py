n, k = [int(i) for i in input().split(' ')]
a = [int(i) - 1 for i in input().split(' ')]
seen = set()
i = 0
steps = 0
while i not in seen:
    seen.add(i)
    i = a[i]
    steps += 1
import code
code.interact(local=dict(globals(), **locals()))
times = k % len(seen)
print(times)
print(seen)
while times > 0:
    i = a[i]
    times -= 1
print(i + 1)
