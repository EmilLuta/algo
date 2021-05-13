n, x, y = map(int, input().split(' '))
a = [int(i) for i in input().split(' ')]
for i in range(n):
    current = a[i]
    wrong = False
    for j in range(max(0, i - x), i):
        if a[j] <= current:
            wrong = True
            break
    for j in range(i + 1, min(i + y + 1, n)):
        if a[j] <= current:
            wrong = True
            break
    if wrong:
        continue
    print(i + 1)
    exit()

