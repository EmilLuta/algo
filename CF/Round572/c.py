VALUE = 0
CANDIES = 1
n = int(input())
a = [int(i) for i in input().split(' ')]
pref = [0]
for i in range(n):
    pref.append(pref[-1] + a[i])

q = int(input())
o = ''
for i in range(q):
    l, r = map(int, input().split(' '))
    o += f'{(pref[r] - pref[l - 1]) // 10}\n'
print(o)
