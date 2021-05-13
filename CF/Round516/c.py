from collections import Counter

def go():
    n = int(input())
    c = Counter(input())
    s = ''
    for i in c:
        s += i * c[i]
    return s

print(go())
