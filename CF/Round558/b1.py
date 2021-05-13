from collections import defaultdict

def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    count = defaultdict(int)
    f = defaultdict(int)
    m = 0
    answer = 0
    for i in range(1, n + 1):
        color = a[i - 1]
        count[f[color]] -= 1
        f[color] += 1
        count[f[color]] += 1
        m = max(m, f[color])
        ok = False
        if count[1] == i:
            ok = True
        elif count[i] == 1:
            ok = True
        elif count[1] == 1 and count[m] * m == i - 1:
            ok = True
        elif count[m - 1] * (m - 1) == i - m and count[m] == 1:
            ok = True
        if ok:
            answer = i
    return answer

print(go())
