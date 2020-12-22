from collections import defaultdict

def countSubstrings(s, queries):
    n = len(s)
    cache = defaultdict(set)
    for k in range(1, n):
        for i in range(0, n - k + 1):
            substring = s[i:i + k]
            for j in range(i, -1, -1):
                cache[(j, i + k)].add(substring)
    out = []
    for q in queries:
        out.append(cache[q[0]], cache[q[1]])
    return out

countSubstrings('abaa', [1, 2])
