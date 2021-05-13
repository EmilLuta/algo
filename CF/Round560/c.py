def go():
    n = int(input())
    a = [i for i in input()]
    if n == 1:
        return '1\n'
    i = 1
    while i < n:
        if a[i] == a[i - 1]:
            a[i - 1] = None
            i += 1
        else:
            i += 2
    a = ''.join(i for i in a if i is not None)
    if len(a) % 2 == 1:
        a = a[:-1]
    return '{}\n{}'.format(n - len(a), a)

print(go())
