def is_good(x, y, l, u, r, d):
    if x < l or x > r or y < d or y > u:
        return True
    return False

def get_accessible(w, h, l, u, r, d):
    dp = [[0] * w for _ in range(h)]
    for i in range(h):
        dp[i][0] = 1
    for j in range(w):
        dp[0][j] = 1
    for i in range(1, h):
        for j in range(1, w):
            if is_good(i, j, l, u, r, d):
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
    return dp[h - 1][w - 1]

def get_answer():
    w, h, l, u, r, d = [int(i) for i in input().split(' ')]
    l -= 1
    u -= 1
    r -= 1
    d -= 1
    total = get_accessible(w, h, -1, -1, -1, -1)
    accessible = get_accessible(w, h, l, u, r, d)
    return accessible / total

t = int(input())
out = ''
for tc in range(1, t + 1):
    answer = get_answer()
    out += "Case #{}: {}\n".format(tc, answer)
print(out)
