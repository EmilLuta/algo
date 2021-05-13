from collections import Counter
def go():
    n = int(input())
    a = Counter(input())
    if n == 1:
        return 'Yes'
    for i in a.values():
        if i > 1:
            return 'Yes'
    return 'No'

print(go())
