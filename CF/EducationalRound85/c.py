t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    a = []
    b = []
    for i in range(n):
        x, y = [int(i) for i in input().split(' ')]
        a.append(x)
        b.append(y)
