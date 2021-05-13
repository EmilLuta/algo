def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    two = a.count(200)
    one = a.count(100)
    if one % 2 == 1:
        return 'NO'
    if two % 2 == 1 and (one == 0 or one % 2 == 1):
        return 'NO'
    return 'YES'

print(go())
