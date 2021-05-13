t = int(input())
out = ''
while t > 0:
    t -= 1
    a, b, c = [int(i) for i in input().split(' ')]
    if b == 0:
        if a == 0:
            out += '1' * (c + 1) + '\n'
            continue
        out += '0' * (a + 1) + '\n'
        continue
    answer = []
    prev = 0
    for i in range(b + 1):
        answer.append(1 - prev)
        prev = answer[-1]
    for i in range(a):
        answer.insert(1, 0)
    for i in range(c):
        answer.insert(0, 1)
    out += ''.join(str(i) for i in answer) + '\n'
print(out)
