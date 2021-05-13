t = int(input())

out = ''

while t > 0:
    t -= 1
    a, b = [int(i) for i in input().split(' ')]
    # x = a % b
    # if x == 0:
        # out += f'0\n'
    # else:
    out += f'{(b - (a % b)) % b}\n'
print(out)
