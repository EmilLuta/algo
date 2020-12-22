t = int(input())
out = ''
for tc in range(1, t + 1):
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    i = 0
    answer = 0
    while i < n:
        if a[i] == k:
            j = i + 1
            while j < n and a[j] != 1 and a[j] + 1 == a[j - 1]:
                j += 1
            if a[j] == 1 and j - i == k - 1:
                answer += 1
            i = j
        else:
            i += 1
    out += 'Case #{}: {}\n'.format(tc, answer)
print(out)
