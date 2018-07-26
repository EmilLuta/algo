from collections import Counter

def go():
    k = int(input())
    x = input()
    a = Counter(x)
    o = ''
    for i in a:
        if a[i] % k != 0:
            return -1
        o += i * (a[i] // k)
    o *= k
    return o

print(go())
