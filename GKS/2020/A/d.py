t = int(input())
tc = 1
while t > 0:
    t -= 1
    n, k = [int(i) for i in input().split(' ')]
    s = []
    for i in range(n):
        s.append(input())
    s.sort()
