def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    if n < 2:
        return -1
    if n == 2 and a[0] == a[1]:
        return -1
    s = sum(a)
    for i in range(len(a)):
        if s - a[i] != a[i]:
            return '{}\n{}'.format(1, i + 1)
    return -1

print(go())
