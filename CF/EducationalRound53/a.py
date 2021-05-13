def go():
    n = int(input())
    a = [i for i in input()]
    if n == 1:
        print('NO')
        return
    for i in range(n - 1):
        if a[i] != a[i + 1]:
            print('YES')
            print(a[i] + a[i + 1])
            return
    if a[len(a) - 1] != a[len(a) - 2]:
        print('YES')
        print(a[len(a) - 1] + a[len(a) - 2])
        return

    print('NO')

go()
