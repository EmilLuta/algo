def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    for i in range(n):
        if a[i] % 2 == 0:
            a[i] -= 1
    return ' '.join(str(i) for i in a)

print(go())
