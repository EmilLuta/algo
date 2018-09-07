def go():
    n = int(input())
    for i in range(n):
        a, b, d = [int(i) for i in input().split(' ')]
        if a > d or b > d:
            print(-1)
        elif a % 2 == b % 2:
            if a % 2 == d % 2:
                print(d)
            else:
                print(d - 2)
        else:
            if a % 2 == b % 2:
                if d % 2 == a % 2:
                    print(d)
                else:
                    print(d - 2)
            else:
                print(d - 1)
go()
