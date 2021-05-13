def go():
    n = int(input())
    a = [i for i in input()]
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            a.pop(i)
            break
    else:
        a.pop()
    return ''.join(a)

print(go())
