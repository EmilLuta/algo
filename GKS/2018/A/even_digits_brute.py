t = int(input())
tc = 1
def is_good(x):
    while x > 0:
        c = x % 10
        x //= 10
        if c % 2 == 1:
            return False
    return True

while t > 0:
    t -= 1
    n = int(input())
    for i in range(n):
        if is_good(n + i):
            print('Case #{}: {}'.format(tc, i))
            tc += 1
            break
        if is_good(n - i):
            print('Case #{}: {}'.format(tc, i))
            tc += 1
            break
