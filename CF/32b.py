def go():
    a = input()
    i = 0
    n = len(a)
    o = ''
    while i < n:
        if a[i] == '.':
            o += '0'
        elif a[i] == '-' and a[i + 1] == '.':
            o += '1'
            i += 1
        else:
            o+= '2'
            i += 1
        i += 1
    return o

print(go())
