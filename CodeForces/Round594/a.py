t = int(input())

o = ''

for _ in range(t):
    n = int(input())
    odd_r = odd_l = even_r = even_l = 0
    for i in input().split(' '):
        x = int(i)
        if x % 2 == 0:
            even_r += 1
        else:
            odd_r += 1
    m = int(input())
    for i in input().split(' '):
        x = int(i)
        if x % 2 == 0:
            even_l += 1
        else:
            odd_l += 1
    o += str(odd_l * odd_r + even_l * even_r) + '\n'
print(o)
