t = int(input())
out = ''
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    out += str(k + (k - 1) // (n - 1)) + '\n'
print(out)
