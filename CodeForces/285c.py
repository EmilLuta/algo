def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    a.sort()
    x = 0
    for i in range(n):
        x += abs(i + 1 - a[i])
    return x

print(go())
