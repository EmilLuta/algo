def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    x = []
    for i in range(len(a) - 1):
        if a[i] >= a[i + 1]:
            x.append(a[i])
    x.append(a[n - 1])
    print(len(x))
    return ' '.join(str(i) for i in x)

print(go())
