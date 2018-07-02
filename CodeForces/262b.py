def go():
    n, k = [int(i) for i in input().split(' ')]
    a = sorted([int(i) for i in input().split(' ')])
    negatives = len([i for i in a if i < 0])
    pos = a[negatives:]
    neg = a[:negatives]
    if len(neg) >= k:
        for i in range(k):
            neg[i] *= -1
    else:
        for i in range(len(neg)):
            neg[i] *= -1
        k = k - negatives
        if k % 2 == 1:
            if neg:
                if pos:
                    if neg[len(neg) - 1] < pos[0]:
                        neg[len(neg) - 1] *= -1
                    else:
                        pos[0] *= -1
                else:
                    neg[len(neg) - 1] *= -1
            elif pos:
                pos[0] *= -1
    return sum(neg) + sum(pos)

print(go())
