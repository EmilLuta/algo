import math
def all_divisors(n) :
    s = set()
    for i in range(1, int(math.sqrt(n) + 1)) :
        if (n % i == 0) :
            s.add(n // i)
            s.add(i)
    if 1 in s:
        s.remove(1)
    if n in s:
        s.remove(n)
    return s


def go():
    n = int(input())
    x = [sum(range(n + 1)), 1]
    divs = all_divisors(n)
    for i in divs:
        s = 1
        j = s + i
        s += j
        while j != 1:
            j += i
            j %= n
            s += j
        x.append(s - 1)
    return ' '.join(str(i) for i in sorted(x))

print(go())
