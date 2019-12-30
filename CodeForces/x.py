t = int(input())

for _ in range(t):
    x = [i for i in input()]
    n = len(x)
    if n == 1:
        print(x[0])
        continue
    o = ''
    if x[0] == x[1]:
        x[0] = None
        x[1] = None
    i = 1
    while i < n:
        if x[i - 1] == x[i]:
            x[i] = None
            x[i - 1] = None
        i += 1
    print(''.join(sorted(list(set([i for i in x if i is not None])))))
