def go():
    from collections import Counter
    n = int(input())
    a = [i for i in input()]
    b = [i for i in input()]
    if Counter(a) != Counter(b):
        return -1
    i = 0
    o = []
    for i in range(n):
        if a[i] == b[i]:
            continue
        else:
            j = i + 1
            while j < n and a[j] != b[i]:
                j += 1
            for k in range(j, i, -1):
                a[k], a[k - 1] = a[k - 1], a[k]
                o.append(k)
    print(len(o))
    return ' '.join(str(i) for i in o)

print(go())
