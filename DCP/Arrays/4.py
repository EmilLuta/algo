# Number of smaller elements to the right
import bisect


a = [int(i) for i in input().split(' ')]
so_far = []
output = []
for item in reversed(a):
    count = bisect.bisect_left(so_far, item)
    output.append(count)
    bisect.insort(so_far, item)

print(list(reversed(output)))