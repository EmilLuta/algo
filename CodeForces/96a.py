def go():
    prev = None
    c = 0
    for i in input():
        if i == prev:
            c += 1
        else:
            prev = i
            c = 1
        if c == 7:
            return 'YES'
    return 'NO'

print(go())
