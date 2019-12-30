def advance_j(i, j, m, time, a, b):
    while j < m and a[i] + time > b[j]:
        j += 1
    return j

def advance_i(i, value, n, time, a):
    while i < n and a[i] + time < value:
        i += 1
    return i

def update_j(value, j, b, m, ta):
    while j < m and value + ta > b[j]:
        j += 1
    return j

def arrival_time(a, b, i, j, n, m, ta, tb):
    ii = i + 1
    while ii < n and a[ii] + ta < b[j]:
        ii += 1
    ii = min(ii, n - 1)
    jj = update_j(a[ii], j, b, m, ta)
    ans_i = (ii, jj, b[jj] + tb)
    jj = min(j + 1, m - 1)
    ii = i
    while ii < n and a[ii] + ta > b[jj]:
        ii += 1
    ii = min(ii, n - 1)
    ans_j = (ii, jj, b[jj] + tb)
    if ans_i[2] > ans_j[2]:
        return ans_i
    return ans_j

n, m, ta, tb, k = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]
b = [int(i) for i in input().split(' ')]
i = j = 0
found = True
for _ in range(k):
    prev_i, prev_j = i, j
    i, j, value = arrival_time(a, b, i, j, n, m, ta, tb)
    if prev_i == i and prev_j == j:
        found = False
        break
if found:
    print(value)
else:
    print(-1)
