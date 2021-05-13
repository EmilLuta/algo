def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    odd = []
    even = []
    for i in a:
        if i % 2 == 0:
            even.append(i)
        else:
            odd.append(i)
    if len(odd) == len(even) or abs(len(odd) - len(even)) == 1:
        return 0
    odd.sort()
    even.sort()
    if len(odd) > len(even):
        return sum(odd[:len(even) + 1])
    return sum(even[:len(odd) + 1])

print(go())
