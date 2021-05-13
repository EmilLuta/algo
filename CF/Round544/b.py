def go():
    n, k  = map(int, input().split(' '))
    a = [int(i) for i in input().split(' ')]
    d = {}
    answer = 0
    for x in a:
        m = x % k
        complement = k - m if m != 0 else 0
        if complement in d:
            answer += 2
            d[complement].pop()
            if len(d[complement]) == 0:
                d.pop(complement)
        else:
            d.setdefault(m, [])
            d[m].append(None)
    return answer

print(go())
