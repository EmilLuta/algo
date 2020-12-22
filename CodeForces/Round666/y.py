a = [1000000000, 1000000000, 1000000000]
n = len(a)

s = sum(a)
base = 1
good = abs(s - n)
for b in range(2, 1000000):
    x = (b ** n - 1) // (b - 1)
    diff = abs(x - s)
    if good > diff:
        good = abs(x - s)
        base = b
print(base, good, s)
