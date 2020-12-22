t = int(input())

out = ''

while t > 0:
    t -= 1
    n = int(input())
    x = input().split(' ')
    output = ['1']
    for i in range(1, n):
        if output[i - 1] == '1':
            output.append('2')
        else:
            output.append('1')
    extra = False
    if output[-1] == output[0] and x[-1] != x[0]:
        output[-1] = '3'
        extra = True
    if extra:
        out += '3\n'
    else:
        out += '2\n'
    out += ' '.join(output)
    out += '\n'
print(out)
