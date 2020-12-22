from math import floor

a, b, n = [int(i) for i in input().split(' ')]
seen = set()
prev = None
seen = set()
for x in range(1, n + 1):
    value = floor((a * x) / b) - a * floor(x / b)
    if prev is None:
        prev = value
        seen.add(value)
        continue
    if value != prev and value in seen:
        print(max(seen))
        break
    seen.add(value)
    prev = value
else:
    print(max(seen))
