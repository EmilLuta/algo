def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    i = -1
    j = n
    s1 = 0
    s2 = 0
    output = 0
    while i < j:
        if s1 > s2:
            j -= 1
            s2 += a[j]
        elif s2 > s1:
            i += 1
            s1 += a[i]
        else:
            output = s1
            j -= 1
            s2 += a[j]
    return output

print(go())
