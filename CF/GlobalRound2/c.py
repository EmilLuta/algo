from collections import Counter

def go():
    n, m = map(int, input().split(' '))
    a = []
    b = []
    for i in range(n):
        a.append(input().split(' '))
    for j in range(n):
        b.append(input().split(' '))
    for i in range(n):
        if sorted(Counter(a[i]).values()) != sorted(Counter(b[i]).values()):
            import code
            code.interact(local=locals())
            return 'No'
    return 'Yes'

print(go())
