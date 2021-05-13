def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    m = max(a)
    i = 0
    t = 0
    while i < n:
        if a[i] == m:
            c_t = 1
            j = i + 1
            while j < n and a[j] == m:
                c_t += 1
                j += 1
            if c_t > t:
                t = c_t
            i = j
        else:
            i += 1
    return t

print(go())
