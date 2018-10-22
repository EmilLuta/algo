def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    a.sort()
    o = 1
    for i in range(n):
        if(a[i] < i // o):
            o += 1
    return o

print(go())
