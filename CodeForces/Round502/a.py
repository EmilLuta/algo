def go():
    n = int(input())
    t = sum([int(i) for i in input().split(' ')])
    l = [t]
    for i in range(n - 1):
        l.append(sum([int(i) for i in input().split(' ')]))
    for i, v in enumerate(sorted(l, reverse=True)):
        if v == t:
            return i + 1
print(go())
