def go():

    n = int(input())
    a = [int(i) for i in input().split(' ')]
    if not 0 in a:
        return -1
    else:
        return int('5' * (a.count(5) // 9 * 9) + '0' * a.count(0))

print(go())
