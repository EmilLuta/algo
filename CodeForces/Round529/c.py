def go():
    n, k = [int(i) for i in input().split(' ')]
    o = 'YES\n'
    if n < k:
        return 'NO'
    if k == n:
        o += ' '.join(str(1) for i in range(n))
        return o
    b = [i for i in bin(n).replace('0b', '')]
    i = len(b) - 2
    ones = 0
    if b[-1] == '1':
        ones += 1
    stack = []
    while i >= 0:
        if b[i] == '1':
            stack.append(2 ** (len(b) - i - 1))
        i -= 1
    if len(stack) + ones == k:
        o += ' '.join(str(i) for i in stack + [1] * ones)
        return o
    if len(stack) + ones > k:
        return 'NO'
    while len(stack) + ones != k and stack:
        x = stack.pop()
        if x == 2:
            ones += 2
        else:
            stack.append(x // 2)
            stack.append(x // 2)
    if len(stack) + ones == k:
        o += ' '.join(str(i) for i in stack + [1] * ones)
        return o
    return 'NO'
print(go())
