# 1) Implement https://codeforces.com/problemset/problem/1168/B
# 2) Try to solve https://codeforces.com/contest/1169/problem/C
#    i) try to solve it in quadratic complexity
#    ii) you can ask for a hint
# 3) Implement https://codeforces.com/problemset/problem/1166/C
# 4) Solve https://codeforces.com/contest/1167/problem/C

#####
# 1 #
#####

s = input()
n = len(s)
l = 0
ans = 0
for i in range(n):
    for j in range(i - 1, l, -1):
        if 2 * j - i < l:
            break
        if s[i] == s[j] == s[j + j - i]:
             ans += ((2 * j - i) - l + 1) * (n - i)
             l = (2 * j - i + 1)

print(ans)
