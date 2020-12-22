def solve():
    n = int(input())
    a = [[1, 0, 0]]
    s = 0
    for i in range(1, n):
        prev = a[-1]
        a.append([2 * prev[1] + prev[0], prev[0], s])
        s += prev[1]
    print(a[n - 1])

t = int(input())

while t > 0:
    t -= 1
    solve()
