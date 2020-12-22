n, k = [int(i) for i in input().split(' ')]

x = 1
out = []
while len(out) < k:
    if x % n != 0:
        out.append(x)
    x += 1
print(out)
print(out[-1])
