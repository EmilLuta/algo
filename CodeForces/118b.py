n = int(input())
s = '0123456789'
for i in s[:n] + s[n::-1]:
    a = int(i)
    print(' '.join(' ' * (n - a) + s[:a] + s[a::-1]))
