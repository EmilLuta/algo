def is_good(a, b):
    if (int(a, 2) & b) % 2 == 0:
        return 1
    return 0

def go():
    a = input()
    b = input()
    c_b = sum(1 for i in b if i == '1')
    c_a = sum(1 for i in range(len(b)) if a[i] == '1')
    c = 0
    if c_b % 2 == c_a % 2:
        c += 1
    for i in range(len(b), len(a)):
        c_b -= int(a[i - len(b)])
        c_b += int(a[i])
        if c_b % 2 == c_a % 2:
            c += 1
    return c
print(go())
