def go():
    k, n, a, b = [int(i) for i in input().split(' ')]
    value = -1
    if k / a > n:
        return n
    if k / b <= n:
        return -1
    low = 1
    high = n - 1
    while low < high:
        mid = (low + high) // 2
        value = mid * a + (n - mid) * b
        if value < k:
            low = mid + 1
        else:
            high = mid
    if low * a + (n - low) * b >= k:
        return low - 1
    return low

Q = int(input())
for q in range(Q):
    print(go())
