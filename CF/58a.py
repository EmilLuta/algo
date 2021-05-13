def go():
    s = input()
    w = 'hello'
    j = 0
    i = 0
    while i < len(s) and j < len(w):
        if s[i] == w[j]:
            j += 1
        i += 1
    if j == len(w):
        return 'YES'
    return 'NO'

print(go())
