input()
c = [0] * 100001
s = set()
for x in map(int, input().split(' ')):
    c[x] = len(s)
    s.add(x)
print(sum(c))
