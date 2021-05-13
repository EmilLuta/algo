def go():
    n, x, y = map(int, input().split(' '))
    a = input()[::-1]
    b = str((10 ** x) + (10 ** y))[::-1]
    total = 0
    for i in range(min(len(a) - 1, len(b) - 1)):
        if a[i] != b[i]:
            total += 1
    return total

print(go())
