def go():
    n, k = map(int, input().split(' '))
    return min(n - k, k - 1) + 3 * n

print(go())