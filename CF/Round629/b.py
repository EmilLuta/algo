from bisect import bisect_left

t = int(input())

x = 1
s = 1
values = []
buckets = {}
while s < 4999950010:
    values.append(s)
    buckets[s] = x
    x += 1
    s += x
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    index = bisect_left(values, k)
    b_pos = buckets[values[index]]
    bb_pos = b_pos - (values[index] - k + 1)
    for i in range(n - 1, -1, -1):
        if i != b_pos and i != bb_pos:
            out += 'a'
        else:
            out += 'b'
    out += '\n'
print(out)
