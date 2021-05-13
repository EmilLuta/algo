def go():
    n, s, t = map(int, input().split(' '))
    if n == s and n == t:
        return 1
    return max(n - s, n - t) + 1

q = int(input())
for _ in range(q):
    print(go())
