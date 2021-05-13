from itertools import permutations

def binary_search(a, x):
    left = 0
    right = len(a)
    while left < right:
        middle = (left + right) // 2
        if a[middle] <= x:
            left = middle + 1
        else:
            right = middle
    if left > 0 and a[left-1] == x:
        return True
    return False

a = [i for i in range(1, int(input()) + 1)]
x = int(input())
pos = int(input())
count = 0
for p in permutations(a):
    if p[pos] != x:
        continue
    if binary_search(p, x):
        count += 1
print(count)
