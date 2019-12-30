from collections import defaultdict

o = ''

t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    i = 0
    bad = False
    keep_a = defaultdict(int)
    keep_b = defaultdict(int)
    while i < n:
        if a[i] != b[i]:
            if bad:
                if i > 0:
                    if b[i] <= b[i - 1]:
                        break
                keep_a[a[i]] += 1
                keep_b[b[i]] += 1
                if keep_a == keep_b:
                    bad = False
                keep_a = defaultdict(int)
                keep_b = defaultdict(int)
            else:
                bad = True
                keep_a[a[i]] += 1
                keep_b[b[i]] += 1
        i += 1
    if len(keep_a):
        o += 'NO\n'
    else:
        o += 'YES\n'
print(o)