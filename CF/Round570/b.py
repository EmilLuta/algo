def go():
    n, k = map(int, input().split(' '))
    a = [int(i) for i in input().split(' ')]
    minimum = min(a)
    maximum = max(a)
    if maximum - minimum > 2 * k:
        return -1
    return minimum + k

Q = int(input())
for q in range(Q):
    print(go())

