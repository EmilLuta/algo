a,b,c,d=map(int,input().split())
l = abs(a - c)
m = abs(b - d)
if a == c:
    print(a + m, b, c + m, d)
elif b == d:
    print(a, b + l, c, d + l)
elif l != m:
    print(-1)
else:
    print(a, d, c, b)
