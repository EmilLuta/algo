# Smallest window to be sorted
n = int(input())
a = list(map(int, input().split(' ')))

start = end = None
max_so_far, min_so_far = float('-inf'), float('inf')
for i in range(n):
    max_so_far = max(max_so_far, a[i])
    if a[i] < max_so_far:
        end = i

for i in range(n - 1, -1, -1):
    min_so_far = min(min_so_far, a[i])
    if a[i] > min_so_far:
        start = i


if start is None:
    print('Nada')
else:
    print('{} - {}'.format(start, end))