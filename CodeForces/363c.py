def go():
    o = ''
    for c in input():
        if len(o) > 2 and o[-1] == c and o[-2] == o[-3]:
            continue
        if len(o) > 1 and o[-2] == o[-1] == c:
            continue
        o += c
    return o
print(go())
