t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    p = [0] + [int(i) for i in input().split(' ')]
    new_p = p[:]
    c = [0] + [int(i) for i in input().split(' ')]
    k = 0
    found = False
    while not found:
        k += 1
        for i in range(1, n + 1):
            j = 0
            found = True
            x = i
            while j < n:
                if c[new_p[x]] == c[x]:
                    x = new_p[x]
                    j += 1
                    continue
                found = False
                break
            if found:
                out += f'{k}\n'
                break
        new_p = [new_p[p[i]] for i in range(n + 1)]
print(out)
