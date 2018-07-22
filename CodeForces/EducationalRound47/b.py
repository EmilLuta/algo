def go():
    a = [int(i) for i in input()]
    i = 0
    c = 0
    while i < len(a):
        if a[i] == 1:
            a[i] = None
            c += 1
        i += 1
    j = 0
    a = [j for j in a if j is not None]
    while j < len(a):
        if a[j] == 2:
            break
        j += 1
    output = ''.join(str(i) for i in a[:j])
    output += '1' * c
    output += ''.join(str(i) for i in a[j:])
    return output

print(go())
