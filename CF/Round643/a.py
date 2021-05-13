t = int(input())
while t > 0:
    t -= 1
    a, k = [int(i) for i in input().split(' ')]
    diff = []
    while k > 1:
        maximum = int(max(str(a)))
        minimum = int(min(str(a)))
        if minimum == 0:
            break
        a = minimum * maximum + a
        k -= 1
    print(a)
