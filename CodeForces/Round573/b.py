d = {
    'm': 10,
    's': 30,
    'p': 60
}

a, b, c = list(sorted([int(i[0]) + d[i[1]] for i in input().split(' ')]))

if (a == b and b == c) or (a == b - 1 and b == c - 1):
    print(0)
    exit()
if a == b - 1 or b == c - 1 or a == b or b == c or a == c - 2 or a == b - 2 or b == c - 2:
    print(1)
    exit()
print(2)
