def search(a, x):
    start = 0
    end = len(a)
    while start + 1 < end:
        middle = (start + end) // 2
        if a[middle] < x:
            start = middle
        else:
            end = middle
    if x == a[end] or x > a[end]:
        return end
    return start

t = int(input())
a = [2]
max_n = 10 ** 9
level = 2
out = ''
while a[-1] <= max_n:
    a.append(a[-1] + level - 1 + 2 * level)
    level += 1
while t > 0:
    t -= 1
    n = int(input())
    s = 0
    while n > 0:
        x = search(a, n)
        s += 1
        n -= a[x]
    if n < 0:
        s -= 1
    out += f'{s}\n'
print(out)
