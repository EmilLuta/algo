n = int(input())

a = [int(i) for i in input().split(' ')]

total = 0

for i in range(n):
    for j in range(n):
        if i > n:
            i, j = j, i
        if sum(a[i:j + 1]) != 0:
            total += 1
print(total)
