def go():
    from collections import Counter
    n, k = (int(i) for i in input().split(' '))
    a = [int(i) for i in input().split(' ')]
    s = sorted(a, reverse=True)[:k]
    s_a = Counter(s)
    j = -1
    output = []
    for i in range(n):
        if a[i] in s_a:
            output.append(str(i - j))
            j = i
            if s_a[a[i]] == 1:
                s_a.pop(a[i])
            else:
                s_a[a[i]] -= 1
    output[-1] = str(int(output[-1]) + i - j)
    print(sum(s))
    return ' '.join(output)

print(go())

