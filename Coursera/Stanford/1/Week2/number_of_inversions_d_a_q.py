def countInversionsDAQ(a):
    n = len(a)
    if n == 1:
        return a, 0
    mid = len(a) // 2
    left_a, left_inv = countInversionsDAQ(a[:mid])
    right_a, right_inv = countInversionsDAQ(a[mid:])
    inv = left_inv + right_inv
    left_n = len(left_a)
    right_n = len(right_a)
    i = 0
    j = 0
    o = [None] * n
    for k in range(n):
        if i >= left_n:
            o[k] = right_a[j]
            j += 1
            continue
        elif j >= right_n:
            o[k] = left_a[i]
            i += 1
        elif i < left_n and left_a[i] < right_a[j]:
            o[k] = left_a[i]
            i += 1
        elif j < right_n and left_a[i] > right_a[j]:
            o[k] = right_a[j]
            j += 1
            inv += left_n - i
    return o, inv

def countInversionsBruteForce(a):
    n = len(a)
    inv = 0
    for i in range(n):
        for j in range(i + 1, n):
            if a[i] > a[j]:
                inv += 1
    return inv


def load_input(filename, trim=None):
    with open(filename, 'r') as f:
        content = f.read()
        data = [int(i) for i in content.split('\n') if i != '']
        if trim is not None:
            return data[:trim]
        return data

data = load_input('input.txt')
# assert countInversionsDAQ(data)[1] == countInversionsBruteForce(data)
print(countInversionsDAQ(data)[1])
