L = int(input())

answer = 0

for i in range(int(L * '9')):
    s = str(i)
    n = len(s)
    if n < L:
        s = '0' * (L - n) + s
    good = True
    for i in range(1, L):
        if s[i] == s[i - 1]:
            good = False
    if good:
        answer += 1
print(answer)
