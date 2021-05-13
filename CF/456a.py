def go():
    n = int(input())
    for i in range(n):
        p, q = [int(i) for i in input().split(' ')]
        if p != q:
            return 'Happy Alex'
    return 'Poor Alex'

print(go())
