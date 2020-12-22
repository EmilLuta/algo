# https://atcoder.jp/contests/abc151/tasks/abc151_c

n, m = [int(i) for i in input().split(' ')]
wa = [0] * n
ac = [0] * n
for _ in range(m):
    problem, status = input().split(' ')
    problem = int(problem) - 1
    if status == 'WA':
        if ac[problem] == 0:
            wa[problem] += 1
        continue
    ac[problem] = 1

no_ac = 0
no_wa = 0

for i in range(n):
    if ac[i] == 1:
        no_ac += 1
        no_wa += wa[i]

print(str(no_ac) + ' ' + str(no_wa))
