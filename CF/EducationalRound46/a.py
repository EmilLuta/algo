def go():
    n = int(input())
    a = []
    b = []
    a_d = {}
    for i in range(n):
        x = input()
        a.append(x)
        a_d.setdefault(x, 0)
        a_d[x] += 1
    for i in range(n):
        x = input()
        if x in a_d:
            a_d[x] -= 1
            a.remove(x)
            if a_d[x] == 0:
                a_d.pop(x)
        else:
            b.append(x)
    if len(b) == 0:
        return 0
    total = 0
    a = list(sorted(a, key=lambda x: len(x)))
    b = list(sorted(b, key=lambda x: len(x)))
    for i in range(len(a)):
        if a[i] == 1:
            total += 1
        else:
            for j in range(len(a[i])):
                if a[i][j] != b[i][j]:
                   total += 1
    return total
print(go())
