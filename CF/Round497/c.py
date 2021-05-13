def go():
    n = int(input())
    a = sorted([int(i) for i in input().split(' ')])
    total = i = j = 0
    while j < n:
        if a[i] == a[j]:
            j += 1
        else:
            break
    while j < n:
        if a[i] < a[j]:
            total += 1
            i += 1
        j += 1
    return total

print(go())
