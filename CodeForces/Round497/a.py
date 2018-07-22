def go():
    vowels = set(['a', 'o', 'u', 'i', 'e'])
    a = [i for i in input()]
    for i in range(len(a) - 1):
        if a[i] not in vowels and a[i + 1] not in vowels and a[i] != 'n':
            return 'NO'
    if a[-1] != 'n' and a[-1] not in vowels:
        return 'NO'
    return 'YES'

print(go())
