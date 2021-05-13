from collections import deque

t = int(input())
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    peaks = deque()
    for i in range(1, k - 2):
        if a[i] > a[i - 1] and a[i] > a[i + 1]:
            peaks.append(i)
    m = len(peaks) + 1
    answer = (m, 1)
    for i in range(k - 2, n - 1):
        if a[i] > a[i - 1] and a[i] > a[i + 1]:
            peaks.append(i)
        if len(peaks) > 0 and peaks[0] == i - (k - 1):
            peaks.popleft()
        if len(peaks) + 1 > m:
            m = len(peaks) + 1
            answer = (m, i - (k - 2) + 1)
    out += f'{answer[0]} {answer[1]}\n'
print(out)
