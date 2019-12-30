def go():
    a = [i for i in input()]
    n = len(a)
    k = int(input())
    q = 0
    s = 0
    o = ''
    for i in a:
        if i == '?':
            q += 1
        if i == '*':
            s += 1
    if n > k:
        if k + 2 * (q + s) < n:
            return 'Impossible'
        x = (n - (q + s)) - k
        for i in range(len(a)):
            if (a[i] == '?' or a[i] == '*'):
                if x != 0:
                    a[i - 1] = None
                    x -= 1
                a[i] = None
        return ''.join(i for i in a if i is not None)
    elif n <= k:
        if s == 0:
            if q == 0 and n == k:
                return ''.join(a)
            return 'Impossible'
        for i in range(len(a)):
            if a[i] == '?':
                a[i] = None
                a[i - 1] = None
            if a[i] == '*' and s > 1:
                a[i] = None
                a[i - 1] = None
                s -= 1
        a = [i for i in a if i is not None]
        index = None
        for i in range(len(a)):
            if a[i] == '*':
                index = len(o) - 1
                continue
            o += a[i]
        x = k - len(o)
        if x == 0:
            return o
        return o[:index] + o[index] * x + o[index:]
print(go())
