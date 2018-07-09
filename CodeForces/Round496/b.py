def go():
    a = list(reversed([i for i in input()]))
    b = list(reversed([i for i in input()]))
    na = len(a)
    nb = len(b)
    total = 0
    i = 0
    j = 0
    while i < na and j < nb and a[i] == b[j]:
        i += 1
        j += 1
    return (na - i)  + (nb - j)

print(go())
