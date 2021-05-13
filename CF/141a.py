from collections import Counter

def go():
    a = input()
    a += input()
    b = Counter(input())
    if b == Counter(a):
        return 'YES'
    return 'NO'

print(go())
