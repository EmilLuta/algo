from collections import Counter
def go():
    n = int(input())
    a = Counter([int(i) for i in input().split(' ')])
    return max(dict(a).values())

    return

print(go())
