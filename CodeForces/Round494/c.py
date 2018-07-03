def go():
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    maxx = float('-inf')
    if k == 1:
        return float(max(a))
    keep = {}
    for i in range(n):
        for j in range(i + k - 1, n):
            if (i, j - 1) in keep:
                current = keep[(i, j - 1)] + a[j]
            elif (i - 1, j) in keep:
                current = keep[(i - 1, j)] - a[i - 1]
            else:
                current = sum(a[i:j + 1])
            keep[(i, j)] = current
            z = current / (j - i + 1)
            if z > maxx:
                maxx = z
    return maxx

print(go())
