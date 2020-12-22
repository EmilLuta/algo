def is_good(row, col, l, u, r, d):
    if l <= col and col <= r and u <= row and row <= d:
        return False
    return True

def get_accessible(w, h, l, u, r, d):
    dp = [[0] * w for _ in range(h)]
    dp[0][0] = 1
    for i in range(h):
        for j in range(w):
            if is_good(i, j, l, u, r, d):
                if i > 0:
                    mult = 0.5
                    if j == w - 1:
                        mult = 1.0
                    dp[i][j] += mult * dp[i - 1][j]
                if j > 0:
                    mult = 0.5
                    if i == h - 1:
                        mult = 1.0
                    dp[i][j] += mult * dp[i][j - 1]
    return dp[h - 1][w - 1]

def get_answer():
    w, h, l, u, r, d = [int(i) for i in input().split(' ')]
    l -= 1
    u -= 1
    r -= 1
    d -= 1
    accessible = get_accessible(w, h, l, u, r, d)
    return accessible

t = int(input())
out = ''
for tc in range(1, t + 1):
    answer = get_answer()
    out += "Case #{}: {}\n".format(tc, answer)
print(out)
