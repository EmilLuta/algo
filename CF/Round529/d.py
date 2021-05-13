def go():
    n = int(input())
    keep = {}
    for i in range(n):
        x, y = [int(j) for j in input().split(' ')]
        keep.setdefault(x, [])
        keep.setdefault(y, [])
        keep[x].append(y)
        keep[y].append(x)
    keys = set(keep.keys())
    output = []
    key = keys.pop()
    output.append(keep[key][0])
    keys.remove(keep[key][0])
    output.append(key)
    output.append(keep[key][1])
    key = keep[key][1]
    while keys:
        keys.remove(key)
        x, y = keep[key]
        if x == output[-2]:
            output.append(y)
            key = y
        elif y == output[-2]:
            output.append(x)
            key = x
        else:
            raise ValueError('wtf')
    if output[-1] != output[0]:
        raise ValueError('wtf')
    return ' '.join(str(i) for i in output[:-1])
print(go())
