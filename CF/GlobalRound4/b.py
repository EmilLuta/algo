s = input()
w = o = total = 0
for i in range(len(s)):
    if s[i] == 'o':
        o += w
    elif i > 0 and s[i - 1] == 'v':
        w += 1
        total += o
print(total)
