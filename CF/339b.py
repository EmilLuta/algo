def go():
    n, m = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    start = 1
    total = 0
    for i in a:
        if i > start:
            total += i - start
            start = i
        elif i < start:
            total += n - start + i
            start = i
    return total

print(go())
