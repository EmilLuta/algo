def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    a.sort()
    m = start = end = 0
    while end < n:
        while end < n and a[end] - a[start] <= 5:
            end += 1
        m = max(m, end - start)
        while start < n - 1 and a[start] == a[start + 1]:
            start += 1
        start += 1
    return max(m, end - start)

print(go())
