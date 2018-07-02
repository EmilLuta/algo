n = int(input())

maxx = 0
count = 0
h_prev = None
m_prev = None
for i in range(n):
    h, m = input().split(' ')
    if h == h_prev and m == m_prev:
        count += 1
    else:
        if count > maxx:
            maxx = count
        count = 1
        h_prev = h
        m_prev = m
print(max(maxx, count))
