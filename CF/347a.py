def go():
    n = int(input())
    a = list(sorted(int(i) for i in input().split(' ')))
    a[0], a[n - 1] = a[n - 1], a[0]
    return ' '.join(str(i) for i in a)

print(go())
