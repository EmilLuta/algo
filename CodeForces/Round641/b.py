t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    answer = 1
    dp = [1] * (n + 1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, n + 1):
        j = 1
        while j * j <= i:
            divs = [j]
            x = i // j
            if x != j:
                divs.append(x)
            for div in divs:
                if i % div == 0 and a[div - 1] < a[i - 1]:
                    dp[i] = max(dp[i], dp[div] + 1)
            j += 1
    out += f'{max(dp)}\n'
print(out)
