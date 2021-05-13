def go():
    a = [i for i in input()]
    if '0' not in a:
        return ''.join(a[1:])
    for i in range(len(a)):
        if a[i] == '0':
            a[i] = None
            break
    return ''.join([i for i in a if i is not None])

print(go())
