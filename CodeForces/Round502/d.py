def go():
    n, m, q = [int(i) for i in input().split(' ')]
    w = [int(i) for i in input().split(' ')]
    s = set()
    a = []
    for i in range(m):
        x = input()
        a.append(x)
    from collections import Counter
    c_a = Counter(a)

    pairs = {}
    output = []
    for i in range(q):
        x = [i for i in input().split(' ')]
        total = 0
        for j in c_a:
            pair = (j, x[0])
            if pair in pairs:
                if int(x[1]) > pairs[pair]:
                    total += c_a[j]
            else:
                value = 0
                for k in range(n):
                    if x[0][k] == j[k]:
                        value += w[k]
                pairs[pair] = value
                if value < int(x[1]):
                    total += c_a[j]
        output.append(str(total))
    return ' '.join(output)

print(go())
