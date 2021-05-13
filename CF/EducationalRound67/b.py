from collections import Counter, defaultdict

n = int(input())
w = input()

keep = defaultdict(list)
o = ''

for i in range(n):
    keep[w[i]].append(i + 1)
m = int(input())
for _ in range(m):
    s = input()
    c = Counter(s)
    output = 0
    for letter in c:
        output = max(output, keep[letter][c[letter] - 1])
    o += '{}\n'.format(output)
print(o)
