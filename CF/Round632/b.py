t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    b = [int(i) for i in input().split(' ')]
    has_positive = False
    has_negative = False
    for i in range(n):
        if b[i] < a[i]:
            if not has_negative:
                out += 'NO\n'
                break
        elif b[i] > a[i]:
            if not has_positive:
                out += 'NO\n'
                break
        if a[i] == 1:
            has_positive = True
        elif a[i] == -1:
            has_negative = True
    else:
        out += 'YES\n'
print(out)

