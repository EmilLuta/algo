def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    x = [None] * n
    for i in range(n):
        x[a[i] - 1] = str(i + 1)
    return ' '.join(x)
print(go())
