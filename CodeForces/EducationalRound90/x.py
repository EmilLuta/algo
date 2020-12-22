s = input()

res = 0
for init in range(0, 10000000):
    cur = init
    ok = True
    for i in range(len(s)):
        res += 1
        if s[i] == '+':
            cur += 1
        else:
            cur -= 1
        if cur < 0:
            ok = False
            break
    if ok:
        break
print(res)
