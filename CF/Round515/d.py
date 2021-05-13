def go():
    n, m, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    current_box = k
    m -= 1
    c = 0
    for i in range(n - 1, -1, -1):
        if a[i] <= current_box:
            current_box -= a[i]
            c += 1
        elif a[i] > current_box:
            current_box = k - a[i]
            if m == 0:
                break
            m -= 1
            c += 1
    return c

print(go())
