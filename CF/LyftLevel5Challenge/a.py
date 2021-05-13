def go():
    n = int(input())
    x, y = [int(i) for i in input().split(' ')]
    a = 1 + 1
    b = n + n
    c = x + y
    distance_w = c - a
    distance_b = b - c
    if distance_w == distance_b:
        return 'White'
    if distance_w < distance_b:
        return 'White'
    return 'Black'

print(go())
