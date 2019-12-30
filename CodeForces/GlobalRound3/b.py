def go():
    n, m, ta, tb, k = [int(i) for i in input().split(' ')]
    a = [int(i) + ta for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    j = 0
    answer = 0
    if k >= n or k >= m:
        return -1

    for i in range(k + 1):
        x = k - i
        while j < m and b[j] < a[i]:
            j += 1
        if j + x >= m:
            return -1
        answer = max(answer, b[j + x] + tb)
    return answer

print(go())
