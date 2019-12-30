n = int(input())
for i in range(n):
    m = input()
    a = input()
    o = ''
    for j in range(len(a)):
        if a[j] == 'E':
            o += 'S'
        else:
            o += 'E'
    print("Case #{}: {}".format(i + 1, o))
