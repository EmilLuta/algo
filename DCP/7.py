def num_encodings(s):
    if s.startswith('0'):
        return 0
    elif len(s) <= 1:
        return 1
    total = 0
    if int(s[:2]) <= 26:
        total += num_encodings(s[2:])
    total += num_encodings(s[1:])
    return total


from collections import defaultdict

def num_encodings(s):
    cache = defaultdict(int)
    cache[len(s)] = 1
    for i in reversed(range(len(s))):
        if s[i] == '0':
            cache[i] = 0
        elif len(s) - 1 == i:
            cache[i] = 1
        else:
            if int(s[i:i + 2]) <= 26:
                cache[i] = cache[i + 2]
            cache[i] += cache[i + 1]
    return cache[0]

print(num_encodings('111'))
