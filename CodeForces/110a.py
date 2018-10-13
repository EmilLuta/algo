def go():
    c = 0
    for i in input():
        if i == '4' or i == '7':
            c += 1
    if c == 4 or c == 7:
        return 'YES'
    return 'NO'

print(go())
