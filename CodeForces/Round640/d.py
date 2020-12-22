t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    alice = bob = 0
    prev_a = prev_b = 0
    i = 0
    j = n - 1
    fw = True
    rounds = 0
    while i <= j:
        curr = 0
        if fw:
            while i <= j and curr <= prev_b:
                curr += a[i]
                i += 1
            alice += curr
            prev_a = curr
        else:
            while i <= j and curr <= prev_a:
                curr += a[j]
                j -= 1
            bob += curr
            prev_b = curr
        rounds += 1
        fw = not fw
    out += f'{rounds} {alice} {bob}\n'
print(out)
