a = []
o = []
n = int(input())


def swap(a, i, j):
    o.append((i, j))
    a[i], a[j] = a[j], a[i]

def swap_with_condition(a, i, j):
    global n
    if i > j:
        i, j = j, i
    if j - i >= n // 2:
        return swap(a, i, j)
    if n - j >= n // 2:
        swap(a, j, n)
        swap(a, i, n)
        return swap(a, j, n)
    if i - 1 >= n // 2:
        swap(a, i, 1)
        swap(a, j, 1)
        return swap(a, i, 1)
    swap(a, i, n)
    swap(a, 1, n)
    swap(a, 1, j)
    swap(a, 1, n)
    return swap(a, i, n)

def go():
    c = 0
    global n
    a = [0] + [int(i) for i in input().split(' ')]
    for i in range(1, n):
        while i != a[i]:
            c += 1
            try:
                swap_with_condition(a, i, a[i])
            except:
                raise ValueError('i: {} a[i]: {} len(a): {}'.format(i, a[i], len(a)))
    output = '{}\n'.format(len(o))
    for i in o:
        output += '{} {}\n'.format(i[0], i[1])
    return output

print(go())
