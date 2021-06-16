s = input()
n = len(s)

answer = 0

for i in range(n):
    for j in range(i + 1, n + 1):
        add = 1
        for x in range(i + 1, j):
            if s[x] == s[x - 1]:
                add = 0
        answer += add
print(answer)
