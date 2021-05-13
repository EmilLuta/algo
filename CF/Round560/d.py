def get_case():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    s = set()
    candidate = min(a) * max(a)
    i = 2
    while i * i <= candidate:
        if candidate % i == 0:
            s.add(i)
            s.add(candidate // i)
        i += 1
    if s == set(a):
        return candidate
    return -1

def go():
    t = int(input())
    output = ''
    for i in range(t):
        output += '{}\n'.format(get_case())
    return output

print(go())
