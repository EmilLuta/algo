def go():
    n = int(input())
    a = sorted([int(i) for i in input().split(' ')])
    j = 0
    total = 0
    for i in range(1, n + 1):
        while j < n and a[j] < i:
            j += 1
        if j == n:
            break
        total += 1
        j += 1

    return total

print(go())
