# def go():
#     n, x = map(int, input().split(' '))
#     a = [int(i) for i in input().split(' ')]
#     cur1 = cur2 = cur = maximum = 0
#     for i in range(len(a)):
#         cur1 = max(0, cur1 + a[i])
#         cur2 = max(cur1, cur2 + x * a[i])
#         cur = max(cur + a[i], cur2)
#         maximum = max(maximum, cur)
#     return maximum

# print(go())

def go():
    minus_inf = float('-inf')
    n, x = map(int, input().split(' '))
    a = [int(i) for i in input().split(' ')]
    dp = []
    for i in range(n):
        dp.append([])
        for _ in range(3):
            dp[i].append([minus_inf, minus_inf, minus_inf])
    dp[0][0][0] = 0
print(go())
