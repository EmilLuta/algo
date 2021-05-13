t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    answer = []
    i = 0
    while n > 0:
        c = n % 10
        x = c * (10 ** i)
        if x != 0:
            answer.append(x)
        n //= 10
        i += 1
    out += f'{len(answer)}\n'
    out += ' '.join(str(i) for i in answer) + '\n'
print(out)
