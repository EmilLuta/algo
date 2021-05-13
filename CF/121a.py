maximum = 10 ** 9
a = []

queue = [4, 7]

element = 0

while element < maximum:
    element = queue.pop(0)
    a.append(element)
    x = element * 10
    queue.append(x + 4)
    queue.append(x + 7)

l, r = (int(i) for i in input().split(' '))

for i in range(len(a)):
    if a[i] >= l:
        break

current = l
total = 0
while current <= r:
    if a[i] > r:
        total += (r - current + 1) * a[i]
        current = a[i]
    else:
        total += (a[i] + 1 - current) * a[i]
        current = a[i] + 1
        i += 1
print(total)


# 1 2 3 4 5 6 7 8 9
# 4 4 4 4 7 7 7 47 47
