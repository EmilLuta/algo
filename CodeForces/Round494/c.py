def go():
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    maxx = float('-inf')
    for i in range(n - k + 1):
        s = sum(a[i:i + k - 1])
        for j in range(i + k - 1, n):
            s += a[j]
            so_far = s / (j - i + 1)
            if so_far > maxx:
                maxx = so_far
    return maxx

print(go())

