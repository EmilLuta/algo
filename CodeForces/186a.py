from collections import Counter

def go():
    a = [i for i in input()]
    b = [i for i in input()]
    a_c = Counter(a)
    b_c = Counter(b)
    if len(a) != len(b) or a_c != b_c:
        return 'NO'
    differences = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            differences += 1
    if differences == 2:
        return 'YES'
    return 'NO'

print(go())
