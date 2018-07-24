def go():
    n, m = (int(i) for i in input().split(' '))
    a = [int(i) for i in input().split(' ')]
    keep = set()
    o = {}
    output = ''
    for i in range(n - 1, -1, -1):
        keep.add(a[i])
        o[i] = len(keep)
    for _ in range(m):
        i = int(input())
        output += '{}\n'.format(o[i - 1])
    return output

print(go())
