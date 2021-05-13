def go():
    n = int(input())
    maxx = float('inf')
    cracks = False
    for i in range(n):
        x = [int(i) for i in input().split(' ')]
        if max(x) <= maxx:
            maxx = max(x)
        elif min(x) <= maxx:
            maxx = min(x)
        else:
            cracks = True
    return 'NO' if cracks else 'YES'

print(go())



